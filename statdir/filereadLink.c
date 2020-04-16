#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int main(void)
{

	char buf[BUFSIZ];
	int n;

	n = readlink("test.sym", buf, BUFSIZ);
	if(n == -1) {
		perror("readlink");
		return 1;
	}

	buf[n] = '\0';
	printf("test.sym : READLINK = %s\n",buf);

	return 0;
}
