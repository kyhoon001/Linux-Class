#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
	int fd;
	struct stat buf;

	fd = open("test.txt",O_RDONLY);
	if(fd == -1) {
		perror("open: test.txt");
		return 1;
	}

	fstat(fd, &buf);
	
	printf("Inode = %d\n", (int)buf.st_ino);
	printf("UID = %d\n", (int)buf.st_uid);



	return 0;
}
