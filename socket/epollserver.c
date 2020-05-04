#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>
#include <string.h>
#include <sys/epoll.h>

#define EPOLL_NO 100

void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}




int main(int argc, char** argv)
{

	int serv_sock, clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	char message[] = "Hello World!";
	struct epoll_event ev, *events;
	socklen_t clnt_addr_size;

	events = (struct epoll_event*)malloc(sizeof(events) * EPOLL_NO);

	int efd = epoll_create(EPOLL_NO);
	ev.events = EPOLLIN;
	ev.data.fd = serv_sock;


	if(argc !=2) {
		printf("Usage : %s<port> \n", argv[0]);
		exit(1);
	}

	printf("%s %s %d\n", __FILE__, __func__, __LINE__);
	serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
	if(serv_sock == -1) {
		error_handling("socket error");
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));//htons(8080);	


	if(bind(serv_sock, (struct sockaddr*) &serv_addr,sizeof(serv_addr))==-1){
		error_handling("bind error");
	}

	if(listen(serv_sock,5) == -1) {
	//5 means how many clients can wait there turns.
	//So, in this code, 5 clients can wait the accept
		error_handling("listen error");
	}

	ev.events = EPOLLIN;
	ev.data.fd = serv_sock;
	epoll_ctl(efd, EPOLL_CTL_ADD, serv_sock, &ev);

	while(1) {
		int n = epoll_wait(efd,events,EPOLL_NO, -1);
	
		for(int i = 0; i < n; i++) {
			if(events[i].data.fd == serv_sock) {
				printf("%s %s %d\n", __FILE__, __func__, __LINE__);
				clnt_sock = accept(serv_sock,(struct sockaddr*) &clnt_addr,&clnt_addr_size);
				printf("%d\n", clnt_sock);
				ev.events = EPOLLIN;
				ev.data.fd = clnt_sock;
				epoll_ctl(efd,EPOLL_CTL_ADD, clnt_sock, &ev);
			}
			else {
				read(events[i].data.fd,message,sizeof(message));
				strcpy(message, "Hello, World!\n");
				write(events[i].data.fd,message,strlen(message));
			}

		}
	}
	close(clnt_sock);
	close(serv_sock);




return 0;
}
