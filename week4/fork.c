#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>




int main(void)
{

	int status;
	pid_t pid;	

	pid =	fork();
	if(pid > 0) {
		printf("[parent] waiting ... %d\n", pid);
		wait(&status);
		printf("[parent] status ... %d\n", status);
	}
	else if(pid == 0) {
		sleep(1);
		printf("[child] bye! \n");
		exit(1234);
	}

	printf("bye bye!\n");


	return 0;
}

