#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char** argv)
{

	pid_t pid;
	int state, fds1[2], fds2[2];
	char buffer[BUFSIZ];
	
	if(pipe(fds1) < 0)
		perror("pipe");
	if(pipe(fds2) < 0)
		perror("pipe");	

	if((pid = fork()) > 0) {
		read(fds1[0], buffer, BUFSIZ);
		printf("[parent] %s\n", buffer);
		strcpy(buffer, "hello parent!");
		write(fds2[1], buffer, sizeof buffer);
		waitpid(pid, &state, 0);
	}

	else if (pid == 0) {
		strcpy(buffer, "hello child");
		write(fds1[1], buffer, BUFSIZ);
		read(fds2[0], buffer, BUFSIZ);
		printf("Child(%d) : %s\n", __LINE__, buffer);
		sleep(1);
	}

	printf("[%s] %s %d\n", __FILE__, __func__, __LINE__);
	printf("[%s] %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}
