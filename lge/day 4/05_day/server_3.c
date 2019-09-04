#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXLINE 4096
typedef struct {
  int	 cnt;			/* initialize to 0 */
  char	*bufptr;			/* initialize to rl_buf */
  char	 buf[MAXLINE];
} Rline;

static ssize_t my_read(int fd, char *ptr, Rline *buf)
{
	if (buf->cnt <= 0) {
		if ( (buf->cnt = read(fd, buf->buf, sizeof(buf->buf))) < 0)
			printf("read error\n");
		else if (buf->cnt == 0)
			return(0);
		buf->bufptr = buf->buf;
	}

	buf->cnt--;
	*ptr = *buf->bufptr++ & 255;
	return(1);
}

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
	int		n, rc;
	char	c, *ptr;

	Rline buf = {0,};
	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(fd, &c, &buf)) == 1) {
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
