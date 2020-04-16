#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	uid_t uid, euid;
	char *name, cname[BUFSIZ];

	uid = getuid();
	euid = geteuid();

	name = getlogin();
	cuserid(cname);

	printf("Login Name = %s, %s UID = %d, EUID = %d\n", name, cname,
	(int)uid, (int)euid);


	return 0;
}
