#if 1
#include <poll.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "socklib.h"

int cli_count=0;

int main()
{
	int ret,fd;
	char buff[1024];
	struct pollfd fds[1024];

	struct sockaddr_in addr;
	struct sockaddr_in cli_addr; 
	socklen_t addrlen;

	sd = Socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof option);

	//fds[cli_count].fd = 0;
	//fds[cli_count++].events = POLLIN;

	Bind(sd, (struct sockaddr*)&addr, sizeof(addr));
	Listen(sd, 20);
	while(1)
	{
		addrlen = sizeof(cli_addr);
		new_sd = Accept(sd, (struct sockaddr*)&cli_addr, &addrlen);
		fds[cli_count] = new_sd;
		fds[cli_count++] = POLLIN;
		printf("client ip=%s, port=%d, 현재 접속자 수 : %d명\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), cli_count);

		while(1)
		{
			poll(fds, cli_count, -1);
			if(fds[0].revents & POLLIN)
			{
				ret = read(0, buff, sizeof buff);
				if(ret == 0)
				{
					for(i = 0; i < cli_count; i++ )	
						if( cli_info[i] == new_sd )
							break;
					cli_count--;
					if( i != cli_count )
						cli_info[i] = cli_info[cli_count];

					printf("연결이 정상 종료 되었습니다., 현재 접속자 수 : %d\n", cli_count);
					break;
				}

				buff[ret-1] = 0;  
				Write(fds[1].fd, buff, ret);
				printf("send to server: [%s]\n", buff);
			}

			close(fd);
			return 0;
		}
#endif

