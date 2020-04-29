#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char ** argv)
{
	struct sockaddr_in adr_inet;
	struct sockaddr_in clnt_inet;
	int z, sck_inet, clnt_sck, cln_len;

	sck_inet = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&adr_inet,0,sizeof(adr_inet));

	adr_inet.sin_family = AF_INET;
	adr_inet.sin_port = htons((argc < 2)? 9000 : atoi(argv[1]));
	adr_inet.sin_addr.s_addr = inet_addr("10.0.2.15");

	z = bind(sck_inet, (struct sockaddr*)&adr_inet, sizeof(adr_inet));
	if(z < 0) {
		perror("bind");
		return -1;
	}

	system("netstat -pa --tcp 2>/dev/null" "| grep inetaddr");



	return 0;
}
