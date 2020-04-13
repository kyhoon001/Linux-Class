#include<stdlib.h>
#include<stdio.h>

int main(int argc, char** argv)
{
	FILE *rfp, *wfp;

	char buf[BUFSIZ];
	int n;
	if((rfp = fopen("fread.c", "r")) == NULL) {
                perror("fopen : fread.c");
                return 1;
        }

	if((wfp = fopen("fread.c", "a")) == NULL) {
		perror("fopen : fread.c");
		return 1;
	}

	while((n = fread(buf,sizeof(char)*2, 3, rfp)) > 0) {
		buf[6] = '\0';
		printf("n = %d, buf = %s\n", n, buf);
		fwrite(buf,sizeof(char)*2);
	}
	fclose(rfp);
	fclose(wfp);

	return 0;
}
