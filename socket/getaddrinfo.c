#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <linux/in6.h>
#include <sys/types.h>
#include <sys/socket.h>



int main(int argc, char** argv)
{
	struct addrinfo hints;
	struct addrinfo *rslt;
	
	char hostname[NI_MAXHOST];
	char addrstr[100];
	void *ptr;
	int status, i = 0;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags != AI_CANONNAME;

	if((status == getaddrinfo(argv[1], NULL, &hints, &rslt)) != 0)

		for(struct addrinfo *aip = rslt; aip != NULL; aip = aip->ai_next) {
			char addrstr[NI_MAXHOST];
			void *pt;
			in_port_t port;

			switch(aip->ai_family) {
				case AF_INET :
					ptr = &((struct sockaddr_in*)aip->ai_addr)->sin_addr;
					port = ntohs(((struct sockaddr_in *)aip)->sin_port);
					break;

				case AF_INET6 :
					ptr = &((struct sockaddr_in6*)aip->ai_addr)->sin6_addr;
					port = ntohs(((struct sockaddr_in6 *)aip)->sin6_port);
					break;
			
				default:
					break;

			}
			
			inet_ntop(aip->ai_family, ptr,addrstr, sizeof addrstr);
			printf("Host name : %s(%s)\n", addrstr,aip->ai_canonname);
		}
	freeaddrinfo(rslt);





	return 0;
}

