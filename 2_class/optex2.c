#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
	int n;
	extern char* optarg; extern int optind;
	
	printf("now optind : %d\n", optind);
	while((n= getopt(argc,argv,"abc:")) != -1) {
		switch(n) {
			case 'a':
				printf("option : a\n");
				break;
			case 'b':
				printf("option : b\n");
				break;
			case 'c':
				printf("option : c, Argument= %s\n", optarg);
				break;
		}
			printf("next Optind : %d\n", optind);
	}
	return 0;
}
