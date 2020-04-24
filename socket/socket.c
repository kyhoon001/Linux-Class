#include <sys/socket.h>



serv_sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
if(serv_sock == -1) {
	error_handling
