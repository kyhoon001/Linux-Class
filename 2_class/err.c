#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(void) {
	FILE *fp;

	if((fp = fopen("mytext", "r")) == NULL) {
		printf("errno=%d\n",errno);
		exit(1);
	}
	fclose(fp);

	return 0;
}
