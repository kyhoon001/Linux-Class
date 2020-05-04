#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

void* send_msg(void* arg);
void* recv_msg(void* arg);
void errsay(char* msg, int code);
char name[BUFSIZ] = "[DEFAULT]";
char msg[BUFSIZ];


int main(int argc, char** argv)
{
	struct sockaddr_in serv_addr, clnt_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_return;

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		printf("connect() error");
		exit(1);
	}

	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);

	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);



	return 0;
}




void * send_msg(void* arg)
{
	printf("send \n");
	int sock=*((int*)arg);
	char name_msg[BUFSIZ];
	while(1) {
		fgets(msg,BUFSIZ, stdin);
		if(!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
			close(sock);
			exit(0);
		}
		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
	}
	printf("send end\n");
	return NULL;
}

void * recv_msg(void* arg)
{
	printf("recv\n");
	int sock=*((int*)arg);
	char name_msg[BUFSIZ];
	int str_len;
	while(1) {
		str_len= read(sock, name_msg, BUFSIZ-1);
		if(str_len==-1)
			return (void*)-1;
		name_msg[str_len] = 0;
		fputs(name_msg, stdout);
	}
	return NULL;
}
