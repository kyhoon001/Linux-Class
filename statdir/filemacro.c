#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main(void)
{
	struct stat buf;
	stat("test.txt", &buf);
	
	printf("Mode = %o (16g : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	if(S_ISFIFO(buf.st_mode)) printf("text.txt : FIFO\n");
	if(S_ISDIR(buf.st_mode)) printf("text.txt : Directory\n");
	if(S_ISREG(buf.st_mode)) printf("text.txt : Regular File\n");

	return 0;
}
