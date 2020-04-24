#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void handler(int signum);
int main(void)
{

	struct sigaction act;
	
	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;

	sigaction(SIGINT, &act, NULL);

	while(1) {
		printf("program is running\n");
		sleep(1);
	}
	return 0;
}

void handler(int signum) {
	char answer[BUFSIZ];
	printf("Do you want to quit? (yes//no) : ");
	scanf("%s", answer);

	if(!strcmp(answer,"yes")) exit(0);
}
