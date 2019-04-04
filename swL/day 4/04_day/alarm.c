#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void my_sig(int signo )
{
	printf("my_sig(%d)\n", signo);
	exit(0);
}
int main()
{
	int i;
	unsigned int temp;
	char buff[128];
	signal( SIGALRM, my_sig );
	alarm(5);
	for(i=0; ; i++)
	{
		printf("%d\n", i );
		sleep(1);
	}
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void my_sig(int signo )
{
	printf("my_sig(%d)\n", signo);
	exit(0);
}
int main()
{
	unsigned int temp;
	char buff[128];
	signal( SIGALRM, my_sig );
	alarm(5);
	read( 0, buff, sizeof buff );
	temp = alarm(0);
	printf("temp=%u\n", temp );
	while(1)
		;
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void my_sig(int signo )
{
	printf("my_sig(%d)\n", signo);
}
int main()
{
	signal( SIGALRM, my_sig );
	alarm(3);
	while(1)
		;
	return 0;
}
#endif

#if 0
#include <unistd.h>
int main()
{
	alarm(3);
	while(1)
		;
	return 0;
}
#endif
