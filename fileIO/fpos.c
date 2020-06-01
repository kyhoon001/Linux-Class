#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	int n;
	long cur;
	fpos_t pos = {12,0};
	char buf[BUFSIZ];

	if((fp = fopen("test.txt","r")) == NULL) {
		perror("fopen: test.txt");
		return 1;
	}

	cur = ftell(fp);
	printf("Offset cur=%d\n", (int)cur);

	n = fread(buf, sizeof(char), 4, fp);
	buf[n] = '\0';
	printf("-- Read Str = %s\n",buf);

	fseek(fp,1,SEEK_CUR);
	fseek(fp,1,SEEK_CUR);

	cur = ftell(fp);
	printf("Offset cur %d\n", (int)cur);

	n = fread(buf, sizeof(char),6,fp);
	buf[n] = '\0';
	printf("-- Read Str = %s\n",buf);

	fsetpos(fp, &pos);


        fgetpos(fp, &pos);
	printf("Offset cur = %d\n", (int)pos.__pos);

	n = fread(buf,sizeof(char),13,fp);
	buf[n] = '\0';
	printf("--Read Str=%s\n",buf);

	fclose(fp);

	return 0;
}
