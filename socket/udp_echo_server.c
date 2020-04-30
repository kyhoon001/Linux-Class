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
	int sock;
	char message[BUFSIZ];
	struct sockaddr_in serv_addr, clnt_addr;
	socklen_t clnt_addr_sz, str_len;

	sock = socket(PF_INET, SOCK_DGRAM,0);
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));	

	strcpy(message, "Hello World!\n");

	while(1) {
		clnt_addr_sz = sizeof(clnt_addr);
		str_len = recvfrom(sock, message, BUFSIZ,0, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);

		sendto(sock, message, str_len, 0, (struct sockaddr*)&clnt_addr, clnt_addr_sz);

	}
	
	close(sock);
	return 0;
}



	
