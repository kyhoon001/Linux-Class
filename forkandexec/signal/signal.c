#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int);

int main()
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR) {
		perror("can't catch SIGUSR1");
		return -1;
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR) {
		perror("can't catch SIGUSR2");
		return -1;
	}
	for(;;)
		pause();



	return 0;
}

static void sig_usr(int signo)
{
	if(signo == SIGUSR1) 
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		fprintf(stderr, "received signal %d\n", signo);
	return;
}
