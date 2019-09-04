#if 1
#include <poll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret,fd;
	char buff[128];
	struct pollfd fds[2];

	fd = open("myfifo", O_RDWR );

	fcntl( 0, F_SETFL, O_NONBLOCK);
	fcntl( fd, F_SETFL, O_NONBLOCK);
	while(1)
	{
		ret = read(0, buff, sizeof buff );
		if( ret < 0 )
		{
			if( errno != EAGAIN )
			{
				perror("read");
				exit(1);
			}
		}
		else
		{
			buff[ret-1] = 0;  
			printf("keyboard=[%s]\n", buff);
		}

		ret = read(fd, buff, sizeof buff );
		if( ret < 0 )
		{
			if( errno != EAGAIN )
			{
				perror("read");
				exit(1);
			}
		}
		else
		{
			buff[ret-1] = 0;  
			printf("myfifo  =[%s]\n", buff);
		}
	}
	close(fd);
	return 0;
}
#endif

