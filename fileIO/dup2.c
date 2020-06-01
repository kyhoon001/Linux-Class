#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	int fd1 = 0;
	char buf[10+1]= "";
	if(argc !=2) {
		fprintf(stderr, "usage: %s [file name]\n", argv[0]);
		return 1;
	}

	fd1 = open(argv[1],O_RDWR | O_APPEND);
	if(fd1 == -1) {
		fprintf(stderr, "failed open %s\n", argv[1]);
		return 1;
	}

	dup2(fd1,STDOUT_FILENO);
	printf("Hello, World!\n");
	system("ifconfig");
	close(fd1);
	return 0;
}
