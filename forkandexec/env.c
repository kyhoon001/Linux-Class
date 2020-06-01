#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void errors(char* msg, int code);
void cleanupaction(void);

int main(int argc, char** argv)
{

	pid_t pid;
	int status;
	putenv("ADDRESS='seoul korea'");
	
	pid = fork();
	if(pid > 0) {
		printf("[parent] PID : %d\n",getpid());
                printf("[parent] PPID : %d\n",getppid());
                printf("[parent] GID : %d\n",getpgrp());
                printf("[parent] SID : %d\n",getsid(0));

		waitpid(pid, &status);
		printf("[parent] status : %d\n",status);
		printf("[parent] ADDRESS: %s\n", getenv("ADDRESS"));
		printf("[parent] PATH : %s\n", getenv("PATH"));

		unsetenv("ADDRESS");

		atexit(cleanupaction);
	}
	else if(pid == 0) {
		printf("[child] PID: %d\n", getpid());
                printf("[child] PPID: %d\n", getppid());
                printf("[child] GID: %d\n", getpgrp());
                printf("[child] SID: %d\n", getsid(0));
                printf("[child] ADDRESS: %d\n", getenv("ADDRESS"));

		atexit(cleanupaction);
		sleep(1);

	}
	else {
		printf("fail to fork child process\n");
	}

	return 0;
}	

void cleanupaction(void) {
	printf("cleanupaction\n");
}
