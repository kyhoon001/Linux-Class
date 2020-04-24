#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>







int main()
{

	int serv_sock, clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	char message[BUFSIZ];
	int clnt_addr_size;
	printf("%s %s %d\n", __FILE__, __func__, __LINE__);
	serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
	if(serv_sock == -1) {
		perror("socket error");
		exit(1);
	}

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
