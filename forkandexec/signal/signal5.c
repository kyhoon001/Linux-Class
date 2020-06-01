#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main()
{

	sigset_t set;
	int count = 3;

	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	sigprocmask(SIG_BLOCK,&set,NULL);

	while(count) {
		printf("don't disturb me (%d) \n", count--);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &set, NULL);

	return 0;
}
