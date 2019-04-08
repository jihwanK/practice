#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;
	int ret;
	char buff[1024];

	fd = open( "myfifo", O_RDWR );
	getchar();
	write( fd, "l", 1 );
	getchar();
	write( fd, "s", 1 );
	getchar();
	write( fd, "\n", 1 );
	close(fd);

	return 0;
}
