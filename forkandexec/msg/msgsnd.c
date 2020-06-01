#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct mymsgbuf {
	long mtype;
	char mtext[80];
};

int main(int argc, char** argv)
{

	key_t key;
	int msgid;
	struct mymsgbuf mesg;

	key = ftok("keyfile", 1);
	msgid = msgget(key, IPC_CREAT|0655);
	if(msgid == -1) {
		perror("msgget");
		exit(1);
	}

	mesg.mtype = 1;
	strcpy(mesg.mtext, "Message Q Test\n");

	if(msgsnd(msgid, (void *) &mesg, 80, IPC_NOWAIT) < 0) {
		perror("megsnd");
		exit(1);
	}

	return 0;
}
