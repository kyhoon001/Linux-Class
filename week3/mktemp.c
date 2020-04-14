#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* fname;
	char fntmp[BUFSIZ];
	char template[32];
	


	fname = tmpnam(NULL);
	printf("1. %s\n", fname);


	tmpnam(fntmp);
	printf("2. %s\n", fntmp);

	fname = tempnam("/tmp", "test");
	printf("3, %s\n", fname);

	strcpy(template, "/tmp/testXXXXXXX");
	fname = mktemp(template);
	printf("4. %s\n", fname);

	return 0;
}


