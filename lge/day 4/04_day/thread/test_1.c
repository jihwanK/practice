#if 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum=0;
int flag=0;

void *foo(void *data)
{
	int local;
	int i,j;

	for(i=0; i<10000; i++ )
	{
		while(flag);
		flag=1;
		local = sum;
		local = local+1;
		for(j=0; j<10000; j++ )
			;
		sum = local;
		flag=0;
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
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum=0;

void *foo(void *data)
{
	int local;
	int i,j;

	for(i=0; i<10000; i++ )
	{
		local = sum;
		local = local+1;
		for(j=0; j<10000; j++ )
			;
		sum = local;
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





