#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main() {
	
	int rfd, wfd, n;
	char buf[10];
	rfd = open("mytest", O_WRONLY | O_CREAT | O_TRUNC);
	if(rfd == -1) {
		perror("error open");
		return 1;
	}

	wfd = open("mytest2", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if(wfd == -1) {
		perror("Open mytest2");
		return 1;
	}


	while((n==read(rfd,buf,6)) > 0) {
		if(write(wfd,buf,n) != n) perror("Write");

	}


	if(n == -1) perror("Read");

	close(rfd);
	close(wfd);
	return 0;
}

