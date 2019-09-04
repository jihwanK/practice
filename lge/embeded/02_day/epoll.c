#if 1
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int ret,fd;
	char buff[128];
	int efd;
	int i, count;
	struct epoll_event event;
    struct epoll_event revents[2];

	fd = open("myfifo", O_RDWR );
	fcntl( fd, F_SETFL, O_NONBLOCK );

  	efd = epoll_create(10);
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event);

	while(1)
	{
		count = epoll_wait(efd, revents, 2, -1);
		for(i=0; i<count; i++ )
		{
			while(1)
			{
				ret = read( revents[i].data.fd, buff, 10 );
				if( ret < 0 )
				{
					if( errno == EAGAIN )
						break;
				}
				else
				{
					buff[ret-1] = 0;  
					printf("[%s]\n", buff);
				}
			}
		}
	}
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int ret,fd;
	char buff[128];
	int efd;
	int i, count;
	struct epoll_event event;
    struct epoll_event revents[2];

	fd = open("myfifo", O_RDWR );

  	efd = epoll_create(10);
    event.data.fd = fd;
    event.events = EPOLLIN;
    epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event);

	while(1)
	{
		count = epoll_wait(efd, revents, 2, -1);
		for(i=0; i<count; i++ )
		{
			ret = read( revents[i].data.fd, buff, 10 );
			buff[ret-1] = 0;  
			printf("[%s]\n", buff);
		}
	}
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int ret,fd;
	char buff[128];
	int efd;
	int i, count;
	struct epoll_event event;
    struct epoll_event revents[2];

	fd = open("myfifo", O_RDWR );

  	efd = epoll_create(10);
    event.data.fd = 0;
    event.events = EPOLLIN;
    epoll_ctl(efd, EPOLL_CTL_ADD, 0, &event);
    event.data.fd = fd;
    event.events = EPOLLIN;
    epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event);

	while(1)
	{
		count = epoll_wait(efd, revents, 2, -1);
		for(i=0; i<count; i++ )
		{
			ret = read( revents[i].data.fd, buff, sizeof buff );
			buff[ret-1] = 0;  
			printf("[%s]\n", buff);
		}
	}
	close(fd);
	return 0;
}
#endif

