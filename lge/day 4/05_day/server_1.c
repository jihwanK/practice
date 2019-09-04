#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t	n, rc;
	char	c, *ptr;

	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
again:
		if ( (rc = read(fd, &c, 1)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break;	/* newline is stored, like fgets() */
		} else if (rc == 0) {
			if (n == 1)
				return(0);	/* EOF, no data read */
			else
				break;		/* EOF, some data was read */
		} else {
			if (errno == EINTR)
				goto again;
			return(-1);		/* error, errno set by read() */
		}
	}

	*ptr = 0;	/* null terminate like fgets() */
	return(n);
}

int main()
{
	int fd;
	int ret;
	char buff[1024];

	fd = open( "myfifo", O_RDWR );

	while( ret = readline( fd, buff, sizeof buff ) )
	{
		write( 1, buff, ret );
	}
	close(fd);

	return 0;
}
