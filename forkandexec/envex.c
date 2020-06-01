#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


void errors(char *msg, int code);
void cleanupaction(void);

int main(int argc, char** argv)
{
	char * envlist[] = {"APPLE=0", "BANANA=1", (char*)0};
	execle("envex_sub","envex_sub",(char*)0, envlist);
	return 0;
}

void errors(char * msg, int code)
{


}
void cleanupaction(void)
{
	printf("cleanupaction");
}
