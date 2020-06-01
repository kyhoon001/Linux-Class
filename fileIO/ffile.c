#include <stdio.h>

int main(int argc, char** argv) {
	FILE* fp;
	unsigned char ch;
	fp = fopen("ffile.c","r");
//	printf("%c\n", fgetc(fp));
	ch = fgetc(fp);
	putchar(ch);
	
	fclose(fp);
	return 0;
}
