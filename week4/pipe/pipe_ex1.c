#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <error.h>
#include <wait.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	pid_t pid;
	int state,fd[2];
	char buffer[BUFSIZ];

	if( (state = pipe(fd)) == -1)
		//perror("pipe() error");
		printf("pipe() error");
	
	if((pid = fork()) > 0) {
		read(fd[0], buffer, BUFSIZ);
		printf("[parent] %s\n", buffer);
		strcpy(buffer, "parent hello.");
		write(fd[1], buffer, sizeof buffer);
		waitpid(pid, &state, 0);
		sleep(3);
	}
	else if(pid == 0) {
		strcpy(buffer, "child hello.");
		write(fd[1], buffer, sizeof buffer);
		sleep(2);
		read(fd[0],buffer,BUFSIZ);
		printf("[child] %s\n", buffer);
//		printf("[%s] %s %d\n", __LINE__, buffer);
	}
//	printf("[%s] %s %d\n", __FILE__,__func__, __LINE__);
	return 0;
}
