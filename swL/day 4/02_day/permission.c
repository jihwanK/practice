#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	struct stat buf;
	char perm[11] = "----------";
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;
	stat( argv[1], &buf );

	for(i=0; i<9; i++ )
	{
		if( (buf.st_mode>>(8-i)) & 1 )
			perm[1+i] = rwx[i%3];
	}
	for(i=0; i<3; i++ )
	{
		if( (buf.st_mode>>(11-i)) & 1 )
		{
			if( perm[(i+1)*3] != '-' )
			 	perm[(i+1)*3] = sst[i];
			else
			 	perm[(i+1)*3] = sst[i]-32;
		}
	}

	printf("%s", perm );
	printf(" %s\n", argv[1] );
	return 0;
}
