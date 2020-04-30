#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
	int sfd, cfd;

	char buf[BUFSIZ];
	socklen_t clt_len;	

	struct sockaddr_in serv_addr, clt_addr; // for bind
	
	if(argc < 2) {
		fprintf(stderr, "Usage : %s [port no]\n", argv[0]);
		exit(1);
	}


	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd < 0) {
		perror("socket() error");
		exit(1);
	}

	printf("socket fd : %d\n",sfd);

	// bind

	memset(&serv_addr,0,sizeof(serv_addr));	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//listen
	
	listen(sfd, 5);
		
	//accept

	
	cfd =  accept(sfd,(struct sockaddr*)&clt_addr, &clt_len);
	

	//recv || send ///// write|| read

	read(cfd, buf, sizeof(buf));
	printf("%s\n", buf);

	strcpy(buf, "Hello World\n");	
	write(cfd, buf, strlen(buf));

	

	close(sfd);
	close(cfd);
	return 0;
}
