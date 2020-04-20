#include <stdio.h>

int main(int argc, char** argv, char* envlist[])
{
	while(*envlist)
		printf("%s\n", *envlist++);


	return 0;
}
