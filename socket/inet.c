#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char** argv)
{
	char * addr1 = "127.0.0.1";
	unsigned long conv_addr;
	conv_addr = inet_addr((argc < 2) ? addr1:argv[1]);
	
	printf("%x %ld\n", conv_addr, conv_addr);
	printf("%x\n", ntohl(conv_addr));

	return 0;
}
