#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>



int main(int argc, char** argv)
{
	pid_t pid;
	int count = 5;
	
	


	if((pid == fork()) > 0) {
//		signal(SIGINT, SIG_IGN); // to prevent kill
		sleep(2);
		kill(pid, SIGINT);
//		raise(SIGINT);
//		kill(getpid(), SIGINT); // getpid() for suiside
		kill(0, SIGINT); // 0 means group
		printf("[parent] bye !\n");
	}
	else if(pid == 0) {
		while(count) {
			printf("[child] count is %d\n", count--);
			sleep(1);
		}
	}

	else printf("fail to fork\n");



	return 0;
}
