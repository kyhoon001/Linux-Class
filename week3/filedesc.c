#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(void) {
	int fd, flags;

	fd = open("mytest.txt",O_RDWR);
	if(fd == -1) {
		perror("open");
		return 1;
	}

	if(fcntl(fd,F_SETFL,flags) == -1) {
		perror("fcntl");
		return 1;
	}

	if(write(fd,"System programming", 12) != 12)
		perror("write");
	close(fd);
}
