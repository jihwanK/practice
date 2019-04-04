#include <pthread.h>
#include <stdio.h>

int sum=0;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex;
pthread_mutexattr_t attr;


int foo(int n)
{
	if(n==1) return 1;
	pthread_mutex_lock( &mutex );  
	sum = foo(n-1) + n;
	pthread_mutex_unlock( &mutex ); 
	return sum;
}


int main()
{
	pthread_mutexattr_init( &attr );
	pthread_mutexattr_settype( &attr , PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init( &mutex , &attr );

	foo(10);
	return 0;
}

