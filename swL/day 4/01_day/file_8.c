#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	char buff[8192];
	int ret;
	fp = fopen("file_1.c", "r");
	while( ret = fread( buff, 1, sizeof buff, fp ) )
	{
		printf("ret = %d\n", ret );
		fwrite( buff, 1, ret, stdout );
		usleep(100000);
	}
	printf("ret = %d\n", ret );
	fclose(fp);
	return 0;
}
