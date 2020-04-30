#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char** argv)
{

	struct sockaddr_in serv_addr;
	socklen_t addr_size;
	int sock, str_len;
	char message[] = "UDP Client", ip_addr[BUFSIZ];

	if(argc != 3) {
		printf("need 2 input\n");
		exit(1);
	}
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	if(sock == -1) {
		printf("sock error\n");
		//fprintf(stderr,"Usage : socket() error\n");
		exit(1);
	}

/*
	struct sockaddr_in serv_addr;
	socklen_t addr_size;
	int str_len, sock;
	char message[] = "UDP Client", ip_addr[BUFSIZ];
  
	if(argc != 3) {
        	printf("Usage : %s [ip] [port]\n", argv[0]);
        	exit(1);
     	}
  
	sock = socket(AF_INET, SOCK_DGRAM, 0);
  	if(sock == -1) {
    //      error_handling("socket() 에러");
        	printf("sock error\n");
          	exit(1);
     	 }

*/


	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

      while(1)
      {
          sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
          addr_size = sizeof(serv_addr);
          str_len = recvfrom(sock, message, BUFSIZ, 0, (struct sockaddr*)&serv_addr, &addr_size);
  
          message[str_len] = '\0';
          inet_ntop(AF_INET, &serv_addr.sin_addr.s_addr, ip_addr, sizeof(ip_addr));
          printf("Message from server : %s\n", message);
          printf("PORT : %d\n", serv_addr.sin_port);
          printf("IP : %s\n", ip_addr);
      }

//	strcpy(message, "Hello from clnt\n");
/*	while(1) {
		printf("start\n");
		sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	//	sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
		printf("sendto\n");
		printf("sendto\n");
		printf("sendto\n");
		addr_sz = sizeof(serv_addr);
		str_len = recvfrom(sock, message, BUFSIZ, 0, (struct sockaddr*)&serv_addr, &addr_sz);
		message[str_len] = '\0';
		//inet_ntop(AF_INET, &serv_addr.sin_addr.s_addr, ip_addr, sizeof(ip_addr));
		printf("Message from server : %s\n",message);
		printf("ip : %s\n", ip_addr);
	}
*/	printf("end\n");

	return 0;
}
