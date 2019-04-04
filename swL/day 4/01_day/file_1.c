#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;
	fp = fopen("file_1.c", "r");
	ch = fgetc( fp );
	fputc( ch, stdout );
	fclose(fp);
	return 0;
}
