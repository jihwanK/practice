#include <stdio.h>
#include <string.h>
typedef struct
{
	int fsize;
	char fname[20];
} F_INFO;

int get_fsize( FILE *fp )
{
	long size;
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	return size;
}

int main(int argc, char **argv)
{
	F_INFO info;
	int i, ret;
	char buff[1024];
	FILE *src, *dst;

	dst = fopen( argv[argc-1], "w" );

	for( i=0; i<argc-2; i++)
	{
		src = fopen( argv[i+1], "r" ); 
		info.fsize = get_fsize( src );
		strcpy(info.fname, argv[i+1]);
		fwrite( &info, sizeof(info), 1, dst );
		while( ret = fread( buff, 1, sizeof buff, src) )
			fwrite( buff, 1, ret, dst );    
		fclose(src);
	}
	fclose(dst);
	return 0;
}
