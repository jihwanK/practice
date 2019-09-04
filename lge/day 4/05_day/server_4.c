#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#define MAXLINE 4096

static pthread_key_t	rl_key;
static pthread_once_t	rl_once = PTHREAD_ONCE_INIT;

static void readline_destructor(void *ptr)
{
	free(ptr);
}

static void readline_once(void)
{
	pthread_key_create(&rl_key, readline_destructor);
}

typedef struct {
  int	 rl_cnt;			/* initialize to 0 */
  char	*rl_bufptr;			/* initialize to rl_buf */
  char	 rl_buf[MAXLINE];
} Rline;
/* end readline1 */

/* include readline2 */
static ssize_t my_read(Rline *tsd, int fd, char *ptr)
{
	if (tsd->rl_cnt <= 0) {
again:
		if ( (tsd->rl_cnt = read(fd, tsd->rl_buf, MAXLINE)) < 0) {
			if (errno == EINTR)
				goto again;
			return(-1);
		} else if (tsd->rl_cnt == 0)
			return(0);
		tsd->rl_bufptr = tsd->rl_buf;
	}

	tsd->rl_cnt--;
	*ptr = *tsd->rl_bufptr++;
	return(1);
}

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
	int		n, rc;
	char	c, *ptr;
	Rline	*tsd;

	pthread_once(&rl_once, readline_once);
	if ( (tsd = pthread_getspecific(rl_key)) == NULL) {
		tsd = calloc(1, sizeof(Rline));		/* init to 0 */
		pthread_setspecific(rl_key, tsd);
	}

	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(tsd, fd, &c)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break;
		} else if (rc == 0) {
			if (n == 1)
				return(0);	/* EOF, no data read */
			else
				break;		/* EOF, some data was read */
		} else
			return(-1);		/* error, errno set by read() */
	}

	*ptr = 0;
	return(n);
}
/* end readline2 */

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
