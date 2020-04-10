#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void) {
	if(access("mytest.txt", R_OK) == -1) {
		perror("Can't found mytext.txt");
		exit(1);
	}

	return 0;
}
