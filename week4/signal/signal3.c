#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


static int num = 0;

int main(int argc, char** argv)
{
	static struct sigaction act;
	void int_handle(int);
	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);

	while(1) {
		printf("i'm sleepy..\n");
		sleep(1);
		if(num >= 3)
			exit(0);
	}


	return 0;
}

void int_handle(int signum)
{
	printf("SIGINT: %d\n", signum);
	printf("int_handle called %d times\n", ++num);
}
