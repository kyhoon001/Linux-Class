#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <assert.h>


int main(int argc, char** argv)
{
	int z;
	int s = -1;
	int so_type = -1;
	socklen_t optlen;

	s = socket(PF_INET, SOCK_STREAM, 0);
	if( s == -1) bail("socket(2)");
	
	optlen = sizeof so_type;

	z = getsockopt(s, SOL_SOCKET, SO_TYPE, &so_type, &optlen);

	if(z) bail("getsockopt(s,SOL_SOCKET, ""SO_TYPE)");

	s = socket(PF_INET, sOCK_STREAM, 0);

	optlen = sizeof sndbuf;
	

	z= getsockopt(s, SOL_SOCKET, SO_SNDBUF, &sndbuf, &optlen);
	optlen = sizeof rcvbuf;
	z = getsockopt(,s, SOL_SOCKET, SO_RCVBUF, &rcvbuf, optlen);


	pritnf("Socket s : %d\n",s);
	printf("send buf : %d bytes\m", sndbuf);
	printf("rcv buf : %d bytes\m", rcvbuf);

	return 0;
}
