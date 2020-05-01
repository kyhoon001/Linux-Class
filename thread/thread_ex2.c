#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_main(void* arg);

int main(int argc, char** argv)
{
	pthread_t t_id;
	void * thr_ret;
	int thread_param = 15;

	if(pthread_create(&t_id, NULL, thread_main,(void*)&thread_param) != 0) {
		puts("pthread_join() error");
		return -1;
	}

	if(pthread_join(t_id, &thr_ret) != 0) {
		puts("pthread_join() error");
		return -1;
	}

	free(thr_ret);
	return 0;
}

void *thread_main(void* arg)
{
        int i;
        int cnt = *((int*)arg);
        for(i = 0; i < cnt; i++) {
                sleep(1);
                puts("running thread");
        }
        return NULL;

}

