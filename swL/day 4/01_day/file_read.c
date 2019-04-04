#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd;
	int ret;
	char buff[100];
	fd = open("file_1.c", O_RDONLY);
	printf("fd = %d\n", fd );
	ret = read( fd, buff, 2 );
	write( 1, buff, ret );
	ret = read( fd, buff, 2 );
	write( 1, buff, ret );
	close(fd);
	return 0;
}

