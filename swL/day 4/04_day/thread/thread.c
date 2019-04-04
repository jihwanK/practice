
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global=6;

void *foo(void *data)
{
	printf("child : global=%d, local=%d\n", ++global, ++*(int*)data);
	return 0;  // pthread_exit(foo());
}

int main()
{
	int local=10;
	pthread_t thread;

	pthread_create( &thread, 0, foo, &local);
	pthread_join( thread, 0);

	//foo(&local);

	printf("parent: global=%d, local=%d\n", global, local);
	return 0;   // exit(main());
}





