#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void cleanupaction(void);

int main(int argc, char **argv) {


	pid_t pid;
	int i;

	for(size_t i = 0; i < 3; i++) {
		printf("before fork[%d]\n", i);
		sleep(1);
	}


	pid = fork();
	if(pid > 0) {
		for(size_t i = 0; i < 7; i++) {
			printf("parent [%d]\n", i);
			sleep(1);
		}
		atexit(cleanupaction);
	}

	else if(pid == 0) {

		for(size_t i = 0; i < 5; i++) {
			printf("child[%d]\n", i);
			sleep(1);
			execl("/bin/ls", "ls", "-l", (char*)0);
		}
	}

	else {
		printf("fail to fork child\n");
	
	}

	return 0;

}


void cleanupaction(void)
{
	printf("Clean-up action\n");
}





