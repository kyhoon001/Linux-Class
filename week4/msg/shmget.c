#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	int shmid;
	key_t keyval;
	
	keyval = 0x1234;
	shmid = shmget(keyval, 1024, IPC_CREAT |IPC_EXCL | 0666);

	if(shmid == -1) {
		perror("shmid");
		return -1;

	}
	return 0;
}
