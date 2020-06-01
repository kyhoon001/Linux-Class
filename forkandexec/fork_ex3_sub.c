#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
	printf("[%s] PPID : %d, PID : %d\n", argv[0],getppid(),getpid());





	return 0;
}
