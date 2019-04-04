#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char buff[8192];
	int ret;
	fd = open("file_1.c", O_RDONLY);
	while( ret = read( fd, buff, sizeof buff ) )
	{
		write( 1, buff,  ret );
		usleep(100000);
	}
	close(fd);
	return 0;
}
