#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	int fd1 = 0, fd2 = 0;
	char buf[10+1]= "";
	if(argc !=2) {
		fprintf(stderr, "usage: %s [file name]\n", argv[0]);
		return 1;
	}

	fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1) {
		fprintf(stderr, "failed open %s\n", argv[1]);
		return 1;
	}

	fd2 = dup(fd1);
	if(fd2 == -1) {
		perror("failed dup");
		return 1;
	}

	read(fd1, buf, 10);
	printf("fd1: %s\n",buf);
	read(fd2,buf,10);
	printf("fd2: %s\n",buf);
	close(fd1);
	close(fd2);
	return 0;
}
