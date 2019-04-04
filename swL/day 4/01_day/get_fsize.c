#include <stdio.h>
#include <string.h>

int get_fsize( FILE *fp )
{
	long size, curr;
	curr = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	fseek(fp, curr, SEEK_SET);
	return size;
}

int main(int argc, char **argv)
{
	int ret;
	char buff[1024];
	FILE *fp;

	fp = fopen( argv[1], "r" ); 
	ret = fread( buff, 1, 20, fp );
	fwrite( buff, 1, ret, stdout );
    ret = get_fsize( fp );
	printf("fsize=%d\n", ret );
	ret = fread( buff, 1, 20, fp );
	fwrite( buff, 1, ret, stdout );
	fclose(fp);
	return 0;
}
