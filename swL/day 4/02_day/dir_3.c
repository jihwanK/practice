#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
void my_ls( char *dname )
{
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	chdir(dname);
	dp = opendir( "." );
	while( p = readdir( dp ))
	{
		stat( p->d_name, &buf );
		printf("%s\n", p->d_name );

		if( S_ISDIR( buf.st_mode) )
		{
			if( strcmp(p->d_name,".") && strcmp(p->d_name,"..") )
				my_ls( p->d_name );
		}
	}
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




