#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void sigHander(int no)
{
	char yesorno[BUFSIZ];
	if(no == SIGINT) {
		scanf("%s", yesorno);
		if(!strcmp(yesorno, "yes"))
			exit(0);

	}
}

int main(int argc, char** argv)
{
	printf("Hello World!\n");
	signal(SIGINT, SIG_IGN);
	sleep(3);
	printf("restart\n");
	signal(SIGINT, SIG_DFL);
	sleep(3);
	printf("Do you want to quit (yes/no)");
	fflush(NULL);
	signal(SIGINT, sigHander);
	sleep(3);




	return 0;
}
