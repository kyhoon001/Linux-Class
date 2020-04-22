#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{

	int shmid;
	int pid;
	
	int *cal_num;
	void *shared_memory = (void*)0;

	shmid = shmget((key_t)0x1234, sizeof(int),0, 0666 | IPC_CREAT );

	if(shmid == -1) {
		perror("shmid");
		exit(0);
	}

	shared_memory = shmat(shmid, (void*)0,0);
	if(shared_memory == (void*)-1) {
		perror("shmat failed :");
		exit(0);
	}
	
	cal_num = (int*) shared_memory;
	pid = fork();
	
	if(pid == 0) {
		shmid = shmget((key_t)0x1234, sizeof(int),0);
		if(shmid == -1) {
			perror("shmget failed : ");
			exit(0);
		}
		shared_memory = shmat(shmid (void*)0, 0666 | IPC_CREAT);
		if(shared_memory == (void*)-1) {
			perror("shmat failed: ");
			exit(0);
		}

		cal_num = (int*) shared_memory;
		*cal_num = 1;

		while(1) {
			*cal_num = *cal_num + 1;
			printf("child %d\n", *cal_num);
			sleep(1);
		}

	}
	else if (pid > 0) {
		while(1) {
			sleep(1);
			printf("parent %d\n", *cal_num);

		}
	}

	return 0;
}
