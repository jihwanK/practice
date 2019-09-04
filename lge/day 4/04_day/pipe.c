#if 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// # ./a.out ls wc 
int main(int argc, char **argv)
{
	int fd[2],i;
	char buff[1024];
	int ret;
	pipe(fd);
	if( fork() == 0 )
	{
		close(fd[0]);
		dup2( fd[1], 1 );
		execlp( argv[1], argv[1], (char*)0 );
		exit(0);
	}
	close(fd[1]);
	dup2( fd[0], 0 );
	execlp( argv[2], argv[2], (char*)0 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int fd[2],i;
	char buff[1024];
	int ret;
	pipe(fd);
	if( fork() == 0 )
	{
		close(fd[0]);
		write( fd[1] , "hello", 5 );
		exit(0);
	}
	close(fd[1]);
	ret = read( fd[0] , buff, sizeof buff );
	buff[ret] = 0;
	printf("[%s]\n", buff );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2],i;
	char buff[1024];
	int ret;
	pipe(fd);
	for(i=0; ; i++)
	{
		write( fd[1] , "a", 1 );
		printf("%d\n", i );
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2],i;
	char buff[1024];
	int ret;
	pipe(fd);
	write( fd[1] , "hello", 5 );
	for(i=0; ; i++)
	{
		ret = read( fd[0] , buff, 1 );
		buff[ret] = 0;
		printf("[%s]\n", buff );
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2];
	char buff[1024];
	int ret;
	pipe(fd);
	write( fd[1] , "hel", 3 );
	write( fd[1] , "lo", 2 );
	ret = read( fd[0] , buff, sizeof buff );
	buff[ret] = 0;
	printf("[%s]\n", buff );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2];
	char buff[1024];
	int ret;
	pipe(fd);
	write( fd[1] , "hello", 5 );
	ret = read( fd[0] , buff, sizeof buff );
	buff[ret] = 0;
	printf("[%s]\n", buff );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd[2];
	pipe(fd);
	printf("fd[0] = %d\n", fd[0] );
	printf("fd[1] = %d\n", fd[1] );
	return 0;
}
#endif
