#if 1
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv, char **envp)
{
	int i;
	for( i=0; argv[i]; i++ )
	{
		printf("argv[%d]=%s\n", i, argv[i] );
	}
	printf("----------\n");
	for( i=0; envp[i]; i++ )
	{
		printf("envp[%d]=%s\n", i, envp[i] );
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	int i;
	for( i=0; argv[i]; i++ )
	{
		printf("argv[%d]=%s\n", i, argv[i] );
	}
	return 0;
}
#endif
