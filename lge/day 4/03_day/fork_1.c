#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int global=6;
int main()
{
	int local=10;
	if( 0==fork() )
	{
		printf("child  : global=%d, &global=%p\n", 
				++global, &global);
		printf("child  : local=%d, &local=%p\n", 
				++local, &local);
	    exit(0);
	}
	wait(0);
	printf("parent : global=%d, &global=%p\n", 
				global, &global);
	printf("parent  : local=%d, &local=%p\n", 
				local, &local);
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	fork();
	printf("after\n");
	return 0;
}
#endif
