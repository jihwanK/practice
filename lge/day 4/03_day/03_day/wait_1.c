#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	int status;
	pid = fork();
	if( pid == 0 )
	{
		while(1);
	}
	printf("pid=%d\n", pid );
	wait(&status);
	if( WIFEXITED( status ) )
		printf("exit(%d)\n", WEXITSTATUS(status) );
	if( WIFSIGNALED(status) ) 
		printf("signo(%d),%s\n", WTERMSIG(status),
		  (WCOREDUMP(status)) ? "(core dumped)" : "");

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	int status;
	pid = fork();
	if( pid == 0 )
	{
		while(1);
	}
	printf("pid=%d\n", pid );
	wait(&status);
	if( WIFEXITED( status ) )
		printf("exit(%d)\n", WEXITSTATUS(status) );
	if( WIFSIGNALED(status) ) 
		printf("signo(%d)\n", WTERMSIG(status) );

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int status;
	if( fork() == 0 )
	{
		exit(7);
	}

	wait(&status);
	printf("status=%d\n", WEXITSTATUS(status) );
	return 0;
}
#endif
