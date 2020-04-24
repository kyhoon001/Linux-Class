#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>
#include <string.h>






int main(int argc, char** argv)
{

	int serv_sock, clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	char message[] = "Hello World!";
	socklen_t clnt_addr_size;


	if(argc !=2) {
		printf("Usage : %s<port> \n", argv[0]);
		exit(1);
	}

	printf("%s %s %d\n", __FILE__, __func__, __LINE__);
	serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
	if(serv_sock == -1) {
		perror("socket error");
		exit(1);
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));//htons(8080);	


	if(bind(serv_sock, (struct sockaddr*) &serv_addr,sizeof(serv_addr))==-1){
		perror("bind error");
		exit(1);
	}

	if(listen(serv_sock,5) == -1) {
		perror("listen error");
		exit(1);
	}

	printf("%s %s %d\n", __FILE__, __func__, __LINE__);
	clnt_sock = accept(serv_sock,(struct sockaddr*) &clnt_addr,&clnt_addr_size);

	write(clnt_sock,message,sizeof(message));
	close(clnt_sock);




return 0;
}
