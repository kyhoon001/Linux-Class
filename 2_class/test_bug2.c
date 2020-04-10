#include <stdio.h>
#include<stdlib.h>

int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int b[5];
	int i;

	for(i= 0; i < sizeof(a); ++i)
		a[i] = i;


	exit(0);

}
