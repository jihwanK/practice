#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	int ch;
	fp = fopen("file_1.c", "r");
	while( (ch = fgetc( fp )) != EOF )
	{
		fputc( ch, stdout );
		fflush( stdout );
		usleep(100000);
	}
	fclose(fp);
	return 0;
}
