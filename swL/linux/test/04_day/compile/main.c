#if 1
#include <stdio.h>
#include <main.h>

int main(int argc, char **argv)
{
	int num;
	num = my_atoi(argv[1]);
	printf("%d\n", ++num );
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <main.h>

int main(int argc, char **argv)
{
	int num;
	num = my_atoi(argv[1]);
	printf("%d\n", ++num );

	return 0;
}

int my_atoi( char *str )
{
	int sum=0;
	int i;
	for(i=0; str[i]!=0 ; i++)
		sum = sum*10 + str[i]-'0';
	return sum;
}
#endif
#if 0
#include <stdio.h>
#include "main.h"

int main(int argc, char **argv)
{
	int num;
	num = my_atoi(argv[1]);
	printf("%d\n", ++num );
	return 0;
}

int my_atoi( char *str )
{
	int sum=0;
	int i;
	for(i=0; str[i]!=0 ; i++)
		sum = sum*10 + str[i]-'0';
	return sum;
}
#endif
#if 0
#include <stdio.h>

int my_atoi( char *str )
{
	int sum=0;
	int i;
	for(i=0; str[i]!=0 ; i++)
		sum = sum*10 + str[i]-'0';
	return sum;
}

int main(int argc, char **argv)
{
	int num;
	num = my_atoi(argv[1]);
	printf("%d\n", ++num );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
// "./a.out"   "1234"
// argv[0]     argv[1]
// argc = 2

int main(int argc, char **argv)
{
	int num;
	num = atoi(argv[1]);
	printf("%d\n", ++num );
	return 0;
}
#endif
