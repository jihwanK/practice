#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *read_thread(void *data)
{
 	int i;
	pthread_mutex_lock(&mutex);
	for(i=0; i<3; i++)
	{
		printf("파일 읽는중...\n");
		sleep(1);
	}
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
	return 0;  
}

void *decode_thread(void *data)
{
 	int i;
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&cond, &mutex);
	for(i=0; i<3; i++)
	{
		printf("파일 디코딩중...\n");
		sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	return 0;  
}

int main()
{
	pthread_t thread[2];

	pthread_create( &thread[0], 0, read_thread, 0);
	pthread_create( &thread[1], 0, decode_thread, 0);
	pthread_join( thread[0], 0);
	pthread_join( thread[1], 0);
	return 0;   
}
#endif





