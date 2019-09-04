#if 1
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int ret,fd;
	char buff[128];
	fd_set readfds;

	fd = open("myfifo", O_RDWR );

	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(fd, &readfds);
		ret = select( fd+1, &readfds, 0, 0, 0);
		if( FD_ISSET(0,&readfds) )
		{
			ret = read(0, buff, sizeof buff );
			buff[ret-1] = 0;  
			printf("keyboard=[%s]\n", buff);
		}

		if( FD_ISSET(fd,&readfds) )
		{
			ret = read(fd, buff, sizeof buff );
			buff[ret-1] = 0;  
			printf("myfifo  =[%s]\n", buff);
		}
	}
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int ret,fd;
	char buff[128];

	fd = open("myfifo", O_RDWR );
	while(1)
	{
		ret = read(0, buff, sizeof buff );
		buff[ret-1] = 0;  
		printf("keyboard=[%s]\n", buff);

		ret = read(fd, buff, sizeof buff );
		buff[ret-1] = 0;  
		printf("myfifo  =[%s]\n", buff);
	}
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int ret;
	char buff[128];
	fd_set readfds;
	int fd=0;
	struct timeval timeout = {2, 500000};

	FD_ZERO(&readfds);
	FD_SET(fd, &readfds);
	ret = select( fd+1, &readfds, 0, 0, &timeout);
	if( ret > 0 )
	{
		ret = read(0, buff, sizeof buff );
		buff[ret-1] = 0;  // "hello\n" => "hello"
		printf("buff=[%s]\n", buff);
	}
	else
	{
		printf("시간이 만료되었습니다.\n");
	}
	return 0;
}
#endif

#if 0
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int ret;
	char buff[128];
	struct timeval timeout = {2, 500000};
	select( 0, 0, 0, 0, &timeout);
	ret = read(0, buff, sizeof buff );
	buff[ret-1] = 0;  // "hello\n" => "hello"
	printf("buff=[%s]\n", buff);
	return 0;
}
#endif
