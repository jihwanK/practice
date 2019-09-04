#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXLINE 4096
static ssize_t my_read(int fd, char *ptr)
{
	static int	read_cnt = 0;
	static char	*read_ptr;
	static char	read_buf[MAXLINE];

	if (read_cnt <= 0) {
		if ( (read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0)
			printf("read error\n");
		else if (read_cnt == 0)
			return(0);
		read_ptr = read_buf;
	}

	read_cnt--;
	*ptr = *read_ptr++ & 255;
	return(1);
}

ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
	int		n, rc;
	char	c, *ptr;

	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(fd, &c)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break;
		} else if (rc == 0) {
			if (n == 1)
				return(0);	/* EOF, no data read */
			else
				break;		/* EOF, some data was read */
		} else
			return(-1);	/* error */
	}

	*ptr = 0;
	return(n);
}
/* end readline */

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
