#if 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int __bionic_cmpxchg(int old_value, int new_value, volatile int* ptr)
{
	int prev, status;
	do {
		__asm__ __volatile__ (
				"ldrex %0, [%3]\n"
				"mov %1, #0\n"
				"teq %0, %4\n"
				"strexeq %1, %5, [%3]"
				: "=&r" (prev), "=&r" (status), "+m"(*ptr)
				: "r" (ptr), "Ir" (old_value), "r" (new_value)
				: "cc");
	} while (__builtin_expect(status != 0, 0));
	return prev != old_value;
}

void spin_lock( int *mutex )
{
	while( __bionic_cmpxchg(0, 1, mutex) );
}
void spin_unlock( int *mutex )
{
	*mutex = 0;
}


int sum=0;
int mutex=0;

void *foo(void *data)
{
	int local;
	int i,j;

	for(i=0; i<10000; i++ )
	{
		spin_lock(&mutex);
		local = sum;
		local = local+1;
		for(j=0; j<10000; j++ )
			;
		sum = local;
		spin_unlock(&mutex);
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





