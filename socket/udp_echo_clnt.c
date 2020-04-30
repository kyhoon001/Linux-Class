#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char ** argv)
{
	int sock, str_len;
	struct sockaddr_in serv_addr, from_addr;
	char message[BUFSIZ];
	socklen_t addr_sz;
	if(argc < 3) {
		printf("need 2 input\n");
		exit(1);
	}
	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock < 0) {
		fprintf(stderr,"Usage : socket() error\n");
		exit(1);
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	strcpy(message, "Hello from clnt\n");
	while(1) {
		printf("start\n");
		sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
		addr_sz = sizeof(from_addr);
		str_len = recvfrom(sock, message, BUFSIZ, 0, (struct sockaddr*)&from_addr, &addr_sz);
		//message[str_len] = 0;
		printf("Message from server : %s\n",message);
	}

	return 0;
}
