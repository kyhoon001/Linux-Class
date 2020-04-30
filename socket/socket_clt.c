#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
	int cfd;
	struct sockaddr_in serv_addr;
	char buf[BUFSIZ];


	if(argc < 3) {
		fprintf(stderr, "Usage :  [server address] [port]");
		exit(1);
	}

	cfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));


	//connect
	connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));


	//write
	strcpy(buf, "Hello, World from client\n");
	write(cfd, buf, strlen(buf));

	//read
	read(cfd, buf, sizeof(buf));
	printf("%s\n", buf);




	close(cfd);
	return 0;
}
