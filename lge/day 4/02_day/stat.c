#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct stat buf;
	stat( argv[1], &buf );
	printf("st_mode=%#x\n", buf.st_mode ); 
	if( S_ISREG(buf.st_mode) )  printf("-");
	if( S_ISDIR(buf.st_mode) )  printf("d");
	if( S_ISCHR(buf.st_mode) )  printf("c");
	if( S_ISBLK(buf.st_mode) )  printf("b");
	if( S_ISFIFO(buf.st_mode) ) printf("p");
	if( S_ISLNK(buf.st_mode) )  printf("l");
	if( S_ISSOCK(buf.st_mode) ) printf("s");

	printf(" %s\n", argv[1] );
	return 0;
}
