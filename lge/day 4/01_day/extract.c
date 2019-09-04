#include <stdio.h>
#include <string.h>
typedef struct
{
	int fsize;
	char fname[20];
} F_INFO;

int main(int argc, char **argv)
{
	F_INFO info;
	int ret, len;
	char buff[1024];
	FILE *src, *dst;

	src = fopen( argv[1], "r" ); 
	while( fread( &info, sizeof(F_INFO), 1, src) )
	{
		dst = fopen( info.fname, "w" );
		while(info.fsize > 0)
		{
			len=(info.fsize<sizeof(buff))?info.fsize:sizeof(buff);
			ret = fread( buff, 1, len, src);
			fwrite( buff, 1, ret, dst );    
			info.fsize -= ret;
		}
		fclose(dst);
	}
	fclose(src);
	return 0;
}
