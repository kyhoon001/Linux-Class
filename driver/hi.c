#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{

	int fd = open("/dev/coco", O_RDWR);
	if (fd == -1) {
		printf("ERROR :: CANNOTREAD /DEV/COCO\n");
		return 0;
	}


	write(fd, "KFC JJANG\n", 9);


	char buf[100];
	read(fd, buf, 100);
	printf("%s\n", buf);

	printf("\nGOOD\n");
	printf("GOOD\n");


	close(fd);
	return 0;
}
