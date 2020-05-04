#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_CLIENTS 16

int main(int argc, char** argv)
{
	fd_set readfds;
	int listen_fd;
	int maxfd, clnt_len, clnt_cnt = 0;
	int clnt_fds[MAX_CLIENTS];
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	char buf[BUFSIZ];

	if(argc < 2) {
		printf("Usage : %s [port-no]\n", argv[0]);
		return 1;
	}
	
	listen_fd = socket(AF_INET, SOCK_STREAM,0);
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(listen_fd,5);

	FD_ZERO(&readfds);
	while(1) {
		FD_SET(0, &readfds); // 0 = stdin

		FD_SET(listen_fd, &readfds);
		maxfd = listen_fd;

		for(int i = 0; i < clnt_cnt; i++) {
			FD_SET(clnt_fds[i], &readfds);
			if(maxfd < clnt_fds[i])
				maxfd = clnt_fds[i];
			
		}
		
		maxfd++;

		select(maxfd, &readfds, NULL,NULL,NULL);
	
		clnt_len = sizeof(clnt_addr);
		if(FD_ISSET(listen_fd, &readfds)) {
			int clnt_fd = accept(listen_fd, (struct sockaddr*)&clnt_addr, &clnt_len);
			printf("Client is Connected\n");
			clnt_fds[clnt_cnt++] = clnt_fd;
		}


		for(int i = 0; i < clnt_cnt; i++) {
			if(FD_ISSET(clnt_fds[i], &readfds)) {
				memset(buf,0,sizeof(buf));
				int len = read(clnt_fds[i], buf, sizeof(buf));
				write(clnt_fds[i],buf,len);
				printf("%s\n", buf); // "%s"
			}
		}

		if(FD_ISSET(0, &readfds)) {
			memset(buf, 0, sizeof(buf));
			int len = read(0, buf, sizeof(buf)); //stdin

			for(int i = 0; i < clnt_cnt; i++) {
				write(clnt_fds[i],buf,len);
			
		}}
	}
	close(listen_fd);

	return 0;
}
