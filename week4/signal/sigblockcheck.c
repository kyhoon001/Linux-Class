#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>



int main(int artc, char** argv)
{

	sigset_t sigset;
	sigset_t pendingset;

	int i  = 0;

	sigfillset(&sigset);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	printf("My PID %d \n", getpid());

	while(1) {
		printf("%d\n", i);
		i++;
		sleep(1);

		if(sigpending(&pendingset) == 0) {
			if(sigismember(&pendingset, SIGUSR1)) {
				printf("BLOCKED Signal : SIGUSR1\n");
				break;
			}
		}

	}

	return 0;
}
