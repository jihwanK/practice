#if 1
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	char *argv[] = { "ls", "-a", "-i", (char *)0};
	printf("prompt > ls -a -i\n");
	if( fork() == 0 )
		execve( "/bin/ls", argv,  0);
	wait(0);
	printf("prompt > \n");
}
#endif
