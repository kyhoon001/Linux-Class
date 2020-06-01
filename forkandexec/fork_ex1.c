#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void cleanupaction(void);
void child_start();


int main(int argc, char ** argv)
{

	pid_t pid;
	int status;

	puts("\t Parent started......!\n");

	if((pid == fork()) > 0) {
		printf("\n\t ** parent: [my pid: %d] my child pid = %d\n", getpid(), pid);
		atexit(cleanupaction);
	}

	else if(pid == 0) {
		child_start();
	}

	else {
		printf("fail to fork child process\n", -1);
	//	err_say("fail to fork child process\n", -1);
	}
	return 0;

}

void cleanupaction(void)
{
	printf("Clean-up action\n");
}

void child_start()
{
	for(size_t i = 0; i < 5; i++) {
		printf("child[%d]\n", i);
		sleep(1);
		execl("/bin/ls", "ls", "-l", (char*)0);
	}
}
