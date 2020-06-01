#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int num = 0;

int main()
{
	static struct sigaction act;

	void int_handle(int);
	
	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	
	while(1) {
		printf("i'm sleepy.. \n");
		sleep(1);
		if(num >= 2) {
			act.sa_handler = SIG_DFL;
			sigaction(SIGINT, &act, NULL);
		}
	}
	return 0;
}

void int_handle(int signum)
{
	printf("SIGINT:%d\n", signum);
	printf("int_handle called %d times\n", ++num);
}
