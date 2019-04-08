#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t key; 
void my_destructor(void* data)
{
	printf("my_destructor(), data=%p\n", data);
	free(data);
}

void foo()
{
	int *count;
	count = pthread_getspecific(key);
	printf("count=%p\n", count);
	if( count == 0 )
	{
		count = (int*)calloc(1,sizeof(int));
		printf("count=%p\n", count);
		pthread_setspecific(key, count);
	}
	printf("foo(), count=%d\n", ++*count);
}

void *handler_1(void *data)
{
	foo();
	foo();
	foo();
	sleep(1);
	return 0;
}

void *handler_2(void *data)
{
	foo();
	foo();
	sleep(1);
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_key_create(&key, my_destructor);
	printf("key=%d\n", key );
	pthread_create( &thread[0], 0, handler_1, 0);
	pthread_create( &thread[1], 0, handler_2, 0);
	pthread_join( thread[0], 0);
	pthread_join( thread[1], 0);
	return 0;
}
#endif














