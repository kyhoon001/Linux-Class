#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum);
int main(int argc, char** argv)
{
	struct sigaction act;
	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;

	sigaction(SIGINT, &act, NULL);
	printf("pause return%d\n", pause());

	return 0;
}



void handler(int signum) {

	printf("\n SIGINT catched\n\n");

}

