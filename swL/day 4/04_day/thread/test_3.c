#if 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *foo(void *data)
{
	int local;
	int i,j;

	for(i=0; i<10000; i++ )
	{
		pthread_mutex_lock(&mutex);
		local = sum;
		local = local+1;
		for(j=0; j<100; j++ )
			;
		sum = local;
		pthread_mutex_unlock(&mutex);
	}

	return 0;  
}

int main()
{
	pthread_t thread[2];

	pthread_create( &thread[0], 0, foo, 0);
	pthread_create( &thread[1], 0, foo, 0);
	pthread_join( thread[0], 0);
	pthread_join( thread[1], 0);

	printf("sum =%d\n", sum);
	return 0;   
}
#endif





