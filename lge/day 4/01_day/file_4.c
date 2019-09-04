#include <stdio.h>
int main()
{
	char buff[100];
	int ret;

	while( ret = fread( buff, 1, sizeof buff , stdin) ) 
		fwrite( buff, 1, ret , stdout );                

	return 0;
}

