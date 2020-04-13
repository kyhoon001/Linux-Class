#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main() {
	int fd = 0;
	unlink("mytest");
	fd = open("mytest", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1) {
		perror("error open");
		return 1;
	}

//	unlink("mytest");  // It means delete the my test file to overwrite
	char buf[10] = "Hello";
	int re = write(fd,buf,10);
	
	if(re == 10) {
		printf("write ok\n");
	}
	else {
		printf("write fail\n");
	}
	
	close(fd);
	return 0;

}
