#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
void my_ls( char *dname )
{
	DIR *dp;
	struct dirent *p;
	chdir(dname);
	dp = opendir( "." );
	while( p = readdir( dp ))
		printf("%s\n", p->d_name );
	closedir(dp);
	chdir("..");
}

int main( int argc, char **argv )
{
	char *dname = ".";
	if( argc == 2 )
		dname = argv[1];
	my_ls( dname );
	return 0;
}




