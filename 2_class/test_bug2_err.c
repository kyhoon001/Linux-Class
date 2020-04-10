#include <stdio.h>
#include<stdlib.h>

int main()
{
	int cnt = 0, score[BUFSIZ];
	
	while(1) {
		printf("score%d? ", cnt+1);
		scanf("%d", score[cnt]);
		if(score[cnt] == -1) 
			break;
		cnt++;
	}

	exit(0);

}
