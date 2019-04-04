#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	int i;
	pid = fork();
	if( pid == 0 )
	{
		for(i=0; i<3; i++ )
		{
			printf("\t\tchild \n");
			sleep(1);
		}
		exit(1);
	}

	//wait(0);
	while(1)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;
}
#endif
