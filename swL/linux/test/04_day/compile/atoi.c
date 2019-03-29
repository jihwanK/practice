#include <main.h>

int my_atoi( char *str )
{
	int sum=0;
	int i;
	for(i=0; str[i]!=0 ; i++)
		sum = sum*10 + str[i]-'0';
	return sum;
}
