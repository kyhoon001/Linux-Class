#include<stdio.h>
#include<stdlib.h>


int main(int argc, char ** argv)
{

	FILE* rfp, *wfp;
	int id, s1, s2, s3, s4, n;

	if((rfp = fopen("test.txt","r")) == NULL) {
		perror("fopen: test.txt");
		return 1;
	}

	if((wfp = fopen("test2.txt","w")) == NULL) {
		perror("fopen: test2.txt");
		return 1;

	}
	
	fprintf(wfp, "num		avg\n");
	while((n = fscanf(rfp, "%d %d %d %d %d", &id, &s1, &s2, &s3, &s4)) != EOF) {
	fprintf(wfp, "%d : %d \n", id, (s1+s2+s3+s4)/4);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}


