#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void sa_handler_usr(int signum);

int main()
{
	struct sigaction sa_usr1;
	struct sigaction sa_usr2;

	memset(&sa_usr1,0,sizeof(struct sigaction));
	sa_usr1.sa_handler = sa_handler_usr;
	sigfillset(&sa_usr1.sa_mask);

	memset(&sa_usr2,0,sizeof(struct sigaction));
        sa_usr2.sa_handler = sa_handler_usr;
	sa_usr2.sa_flags = SA_NODEFER;
        sigemptyset(&sa_usr2.sa_mask);

	sigaction(SIGUSR1, &sa_usr1, NULL); //filled sa_mask
	sigaction(SIGUSR2, &sa_usr2, NULL); //emptyed sa_mask


	printf("[MAIN] SIGNAL-Handler installed, pid(%d)\n", getpid());
	for(;;) {
		pause();
		printf("[MAIN] Recv SIGNAL...\n");
	}
	return EXIT_SUCCESS;

}


void sa_handler_usr(int signum)
{
	int i;
	for(i = 0; i< 10; i++) {
		printf("\t Signal(%s):%d sec.\n", signum == SIGUSR1? "USR1" : "USR2", i);
	sleep(1);
	}
}

