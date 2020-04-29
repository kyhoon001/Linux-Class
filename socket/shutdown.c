
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>


#ifndef SHUT_WR
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2
#endif

int main(int argc, char** argv)
{
	int z, s[2];
	char * msgp, buf[80];
	pid_t chpid;

	z = socketpair(AF_LOCAL, SOCK_STREAM,0, s);

	if(z < 0) {
		perror("socketpair");
		return -1;
	}

	if((chpid = fork()) == (pid_t)-1) {
		perror("fork");
		return -1;
	}


	else if(chpid == 0) {
		char rxbuf[80];
		printf("Parent PID : %d\n", getppid());
		close(s[0]);
		s[0] = -1;
		msgp = "%A %d-%b-%Y %l:%M %p";
		printf("Sending Message : %s\n",msgp);
		fflush(stdout);

		z = write(s[1],msgp,strlen(msgp));
		if( z<0) {
			perror("write");
			return -1;
		}
		if(shutdown(s[1],SHUT_WR) == -1) {
			perror("shutdown");
			return -1;
		}
		z = read(s[1], rxbuf, sizeof(rxbuf));

		if(z<0) {
			perror("read");
			return -1;
		}

		rxbuf[z] = '\0';
		printf("Received Message : %s\n", rxbuf);
		fflush(stdout);
		close(s[1]);

	}

	else {
		int status;
		char txbuf[80];
		time_t td;
		printf("Child Pid : %d\n",chpid);
		fflush(stdout);
		close(s[1]);
		s[1] = -1;

		z = read(s[0],buf,sizeof(buf));
		
		if(z<0) {
			perror("read");
			return -1;
		}

		buf[z] = '\0';
		time(&td);
		strftime(txbuf, sizeof(txbuf), buf, localtime(&td));

		z = write(s[0], txbuf, strlen(txbuf));
		if(z < 0) {
			perror("write");
			return -1;
		}
	
		close(s[0]);
		waitpid(chpid, &status, 0);
		return 0;
	}
	
	return 0;
}

