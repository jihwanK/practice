#if 1
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	pid = fork();
	if( pid > 0 )
		printf("parent\n");
	else if( pid == 0 )
		printf("child \n");
	else
		printf("error \n");
	return 0;
}
#endif
