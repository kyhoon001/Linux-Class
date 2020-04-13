#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	FILE * fp;
	int n;
	fpos_t cur;
	char buf[BUFSIZ];
	
	if((fp = fopen("test.txt","r")) == NULL) {
		perror("fopen:test.txt");
		return 1;
	}

	cur = ftell(fp);
	printf("Offset cur = %d\n", int(cur));

	n = fread(buf, sizeof(char),4, fp);
	buf[n] = '\0';
	printf("--Read Str = %s\n", buf);
	
	fseek(fp, 1, SEEK_CUR);
	fseek(fp, 1, SEEK_CUR);

	cur = ftell(fp);
	printf("Offset cur = %d\n", int(cur));
	
