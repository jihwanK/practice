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
	printf("%s : \n", dname );
	while( p = readdir( dp ))
	{
		printf(" %s", p->d_name );
	}
	printf("\n\n");
	rewinddir(dp);
	while( p = readdir( dp ))
	{
		lstat( p->d_name, &buf );
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




