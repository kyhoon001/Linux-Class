#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>


int main(int argc, char ** argv)
{
	int sock, str_len;
	char message[BUFSIZ], ip_addr[BUFSIZ];
	struct sockaddr_in serv_addr, clnt_addr;
	socklen_t clnt_addr_sz;

	sock = socket(AF_INET, SOCK_DGRAM,0);
	if(sock < 0) {
		fprintf(stderr, "socket() error\n");
		exit(1);
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		fprintf(stderr,"bind error\n");	
		exit(1);
	}

//	strcpy(message, "Hello World!\n");

	while(1) {
		clnt_addr_sz = sizeof(clnt_addr);
		str_len = recvfrom(sock, message, BUFSIZ,0, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);

		sendto(sock, message, str_len, 0, (struct sockaddr*)&clnt_addr, clnt_addr_sz);

	}

	printf("Message : %s\n", message);
	inet_ntop(AF_INET, &clnt_addr.sin_addr.s_addr, ip_addr, sizeof(ip_addr));

	printf("ip : %s\n", ip_addr);
	

	close(sock);
	return 0;
}



	
