#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

void file_type( char *perm , struct stat *buf )
{
	if( S_ISDIR(buf->st_mode) )  perm[0] = 'd'; 
	if( S_ISCHR(buf->st_mode) )  perm[0] = 'c'; 
	if( S_ISBLK(buf->st_mode) )  perm[0] = 'b'; 
	if( S_ISFIFO(buf->st_mode) ) perm[0] = 'p'; 
	if( S_ISLNK(buf->st_mode) )  perm[0] = 'l'; 
	if( S_ISSOCK(buf->st_mode) ) perm[0] = 's'; 
}

void file_perm( char *perm , struct stat *buf )
{
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;

	for(i=0; i<9; i++ )
	{
		if( (buf->st_mode>>(8-i)) & 1 )
			perm[1+i] = rwx[i%3];
	}
	for(i=0; i<3; i++ )
	{
		if( (buf->st_mode>>(11-i)) & 1 )
		{
			if( perm[(i+1)*3] != '-' )
			 	perm[(i+1)*3] = sst[i];
			else
			 	perm[(i+1)*3] = sst[i]-32;
		}
	}
}

int main( int argc, char **argv )
{
	struct stat buf;
	struct passwd *pwd;
	struct group *grp;
	char perm[11] = "----------";
	stat( argv[1], &buf );
	file_type( perm, &buf );
	file_perm( perm, &buf );

	printf("%s", perm );
	printf(" %d", buf.st_nlink );
	pwd = getpwuid(buf.st_uid);
	printf(" %s", pwd->pw_name );
	grp = getgrgid(buf.st_gid);
	printf(" %s", grp->gr_name );
	printf(" %d", buf.st_size );
	printf(" %d", buf.st_mtime );
	printf(" %s\n", argv[1] );
	return 0;
}










