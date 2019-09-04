#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	signal( SIGCHLD, SIG_IGN );
	if( fork() == 0 )
		exit(7);

	while(1)
		;
	return 0;
}
