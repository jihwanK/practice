#if 1
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	sigset_t set;
	sigset_t oldset;
	int i;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, &oldset);
	for(i=0; i<3; i++)
	{
		printf("매우 중요한 일 처리중...\n");
		sleep(1);
	}
	sigprocmask(SIG_SETMASK, &oldset, 0);

	while(1)
		;
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	int i;
	signal( SIGINT, SIG_IGN);
	for(i=0; i<3; i++)
	{
		printf("매우 중요한 일 처리중...\n");
		sleep(1);
	}

	while(1)
		;
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define SIGINT (2)

typedef void(*handler_t)(int);

handler_t signal( int , handler_t);
handler_t old;

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	signal( SIGINT , old );
}
int main()
{
	old = signal( SIGINT , my_sig );
	while(1)
		;
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define SIGINT (2)

void (*signal( int , void(*)(int) ))(int);
void (*old)(int);
void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	signal( SIGINT , old );
}
int main()
{
	old = signal( SIGINT , my_sig );
	while(1)
		;
	return 0;
}
#endif
#if 0
#include <signal.h>
#include <stdio.h>
void (*old)(int);
void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	signal( SIGINT , old );
}
int main()
{
	old = signal( SIGINT , my_sig );
	while(1)
		;
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define SIGINT   (2)
void signal( int , void (*)(int)  );

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
}

int main()
{
	signal( SIGINT , my_sig );
	while(1)
		;
	return 0;
}
#endif

#if 0
#include <signal.h>
int main()
{
	signal( SIGINT , SIG_IGN );
	signal( SIGQUIT , SIG_IGN );
	signal( SIGKILL , SIG_IGN );
	while(1)
		;
	return 0;
}
#endif

#if 0
int main()
{
	while(1)
		;
	return 0;
}
#endif
