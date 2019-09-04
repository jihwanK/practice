#include <stdio.h>

int main()
{
	char buff[100];
	int ret;

	FILE *fp;
	fp = fopen("file_1.c", "r");
	ret = fread( buff, 1, 2, fp);
	fwrite( buff, 1, ret , stdout ); 
	getchar();

	ret = fread( buff, 1, 2, fp);
	fwrite( buff, 1, ret , stdout ); 
	fclose(fp);
	return 0;
}

