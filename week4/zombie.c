#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, child;
	int data = 10;
	int state;

	pid = fork();
	if(pid == -1)
		fprintf(stderr, "fork failed, process id = %d\n", pid);

	printf("fork success. process id = %d\n", pid);

	if(pid == 0) {
		data += 10;
		sleep(10);
	}
	else {
		data -= 10;
		do {
			sleep(3);
			puts("wait for 3 seconds");
			child = waitpid(-1, &state, WNOHANG);
	}while(child == 0);

	printf("Child process id = %d, return value = %d\n", child, WEXITSTATUS(state));
	printf("data : %d\n", data);

	return 0;
	}
}


