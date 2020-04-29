#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char ** argv)
{
	struct hostent *myent;

	if(argc < 2) {
		fprintf(stderr, "usage :%s [domain name]\n", argv[0]);
		exit(1);
	}

	myent = gethostbyname(argv[1]);
	
	printf("Host Name : %s\n", myent->h_name);
	
	for(int i = 0; myent->h_aliases[i]; i++) {
		printf("Alias %d:%s\n",i+1,myent->h_aliases[i]);
	}

	printf("Address Type :%s\n",(myent->h_addrtype==AF_INET)? "AF_INET" : "AF_INET6");

	while(*myent->h_addr_list != NULL) {
		printf("%s\n",inet_ntoa(*(struct in_addr*)*myent->h_addr_list++));
	}

	return 0;
}	
