#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *rfp, *wfp;
	int c;

	if((rfp = fopen("text.txt","r")) == NULL) {
		perror("fopen: text.txt");
		return 1;

	}

	if ((wfp = fopen("text2.txt", "a")) == NULL) {
		perror("fopen:text2.txt");
		return 1;
	}

	while((c = fgetc(rfp)) != EOF) {
		fputc(c, wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}
