#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	char buff[256];
	fp = fopen("file_1.c", "r");
	while( fgets( buff, sizeof buff, fp ) )
	{
		fputs( buff, stdout );
		usleep(100000);
	}
	fclose(fp);
	return 0;
}
