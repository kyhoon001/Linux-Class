#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>
#include <string.h>


#include <fcntl.h>

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
	socklen_t clnt_addr_size;

	char fname[BUFSIZ];
	printf("please enter the target file's name : ");
	scanf("%s",fname);
	printf("\n");

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

	clnt_addr_size = sizeof(clnt_addr);
	printf("%s %s %d\n", __FILE__, __func__, __LINE__);
	clnt_sock = accept(serv_sock,(struct sockaddr*) &clnt_addr,&clnt_addr_size);


////////////////////////////////////////////////////////
	FILE * fp;
	int c;
	if((fp=fopen(fname,"r")) == NULL) {
		error_handling("fopen error");
	}


	char buf2[BUFSIZ];

	inet_ntop(AF_INET, &clnt_addr.sin_addr.s_addr,buf2,sizeof(buf2));
	printf("inet_ntop : %s\n",buf2);



	while((c = fgetc(fp)) != EOF) { 

		//write(clnt_sock,c,sizeof(message));//??????
	//	z = read(c,buf,sizeof(buf));
		
		write(clnt_sock,&c,sizeof(int));
	}
////////////////////////////////////////////////////////
	//write(clnt_sock,message,sizeof(message));




	close(clnt_sock);
	close(serv_sock);




return 0;
}
