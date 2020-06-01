#include <unistd.h>
#include <stdio.h>


int main(void)
{
	pid_t pid;
	
	if((pid = fork()) >0) {
		printf("[fork_ex3] PPID : %d, PID : %d\n", getppid(), getpid());

	sleep(1);
	}
	else if (pid == 0) {
		printf("child [fork_ex3] PPID : %d, PID : %d\n", getppid(), getpid());
		execl("fork_ex3_sub", "fork_ex3_sub", (char*)0);
		printf("execl error");
	}	




	return 0;


}
