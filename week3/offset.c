#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>


int main() {
	int fd = 0, n;
	off_t start, cur;
	char buf[256];

	fd = open("mytest", O_RDONLY);
	if(fd == -1) {
		perror("error open");
		return 1;
	}
	
	start = lseek(fd,0,SEEK_CUR);
	printf("start : %d\n", (int)start);
	
	n = read(fd, buf, 255);
	if( n == -1) perror("Read");

	printf("Offset start=%d, Reead str = %s, n = %d\n", (int)start,buf,n);
	cur = lseek(fd,5,SEEK_SET);

	printf("Offset cur =%d\n", (int)cur);

	start = lseek(fd,5,SEEK_SET);
	n = read(fd,buf,255);
	buf[n] = '\n';
	write(STDOUT_FILENO, buf, sizeof(buf));
	printf("%d %d %d %d \n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, fd);
	close(fd);
	return 0;
}
