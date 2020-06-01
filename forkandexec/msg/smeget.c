#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{


	int semid;
	semid = semget((key_t)12345, 1, 0666 | IPC_CREAT);
	if(semid == -1) {
		perror("semget");
		exit(0);
	}

	return 0;
}
