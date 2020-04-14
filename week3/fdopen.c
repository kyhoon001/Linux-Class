#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int  main()
{
	FILE *fp;
	int fd, n;
	char str[BUFSIZ];

	fd = open("test.txt", O_RDONLY);
	if(fd == -1) {
		perror("open");
		return 1;
	}

	read(fd, str, BUFSIZ);
	printf("read : %s \n", str);
	
	memset(str, 0, BUFSIZ);
	lseek(fd, 0, SEEK_SET);


	fp = fdopen(fd,"r");
	
	fgets(str,BUFSIZ, fp);
	printf("Read : %s\n", str);
	
	fclose(fp);
	return 0;
}
