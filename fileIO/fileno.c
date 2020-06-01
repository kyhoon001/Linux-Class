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

	fp = fopen("test.txt","r");

	if(fp == NULL) {
		perror("fopen");
		return 1;
	}

	fd = fileno(fp);
	printf("fd: %d\n", fd);
	
	n = read(fd, str, BUFSIZ);

	printf("read : %s \n", str);
	
	memset(str, 0, BUFSIZ);
	lseek(fd, 0, SEEK_SET);


	fp = fdopen(fd,"r");
	
	fgets(str,BUFSIZ, fp);
	printf("Read : %s\n", str);
	
	fclose(fp);
	return 0;
}
