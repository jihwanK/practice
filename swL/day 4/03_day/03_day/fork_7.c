#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo );
	while( wait(0) > 0 )
		;
}
int main()
{
	pid_t pid;
	int i,j;
	signal( SIGCHLD, my_sig );
	for(i=0; i<5; i++ )
	{
		pid = fork();
		if( pid == 0 )
		{
			for(j=0; j<i+1; j++ )
			{
				printf("\t\tchild \n");
				sleep(1);
			}
			exit(1);
		}
	}

	while(1)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;
}
#endif
