
#if 1
#include <unistd.h>
#include <stdio.h>
int main()
{
	int status;
	fork(&status);
	if( status == 1 )
		printf("parent\n");
	else if( status == 2 )
		printf("child \n");
	return 0;
}
#endif
