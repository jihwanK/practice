#include <fcntl.h>
#include <unistd.h>
// ./a.out xxx
int main( int argc, char **argv )
{
	char buff[1024];
	int ret;
	int fd;
	
	if( argc==2 )
	{
		close(0);  // fd_array = 0;
		fd = open(argv[1], O_RDONLY );  // fd_array[0] = file;
	}

	while( ret = read( 0, buff, sizeof buff ) )
		write( 1, buff,  ret );

	if( argc == 2 )
		close(fd);
	return 0;
}
