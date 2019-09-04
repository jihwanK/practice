#include <sys/types.h>       
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <pthread.h> 
#include "socklib.h"

int cli_info[100];
int cli_count=0;

int main()
{
	int i,j;
	char buff[1024];
	fd_set readfds;
    int sd, new_sd, max_sd;
	int ret;
	pthread_t thread;
	int option = 1;
	struct sockaddr_in addr;
	struct sockaddr_in cli_addr; 
	socklen_t addrlen;
	sd = Socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof option);

	Bind(sd, (struct sockaddr*)&addr, sizeof(addr));
	Listen(sd, 20);
	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(sd, &readfds);
		max_sd = sd;
		for(i=0; i<cli_count; i++)
		{
			FD_SET(cli_info[i], &readfds);
			if( max_sd < cli_info[i] )
				max_sd = cli_info[i];
		}
		select( max_sd+1, &readfds, 0, 0, 0);
		if( FD_ISSET( sd, &readfds ) )
		{
			addrlen = sizeof( cli_addr );
			new_sd = Accept(sd, (struct sockaddr*)&cli_addr, &addrlen);
			cli_info[cli_count++] = new_sd;
			printf("client ip=%s, port=%d, 현재 접속자 수 : %d명\n", 
					inet_ntoa(cli_addr.sin_addr),
					ntohs(cli_addr.sin_port), cli_count);
		}
		for(i=0; i<cli_count; i++)
		{
			if( FD_ISSET( cli_info[i], &readfds ) )
			{
				ret = Read( cli_info[i], buff, sizeof buff );
				if( ret == 0 )
				{
					Close(cli_info[i]);
					--cli_count;
					if( i != cli_count )
						cli_info[i] = cli_info[cli_count];

					printf("연결이 정상 종료 되었습니다., 현재 접속자 수 : %d\n",
							cli_count);
					break;
				}
				Write( 1, buff, ret );
				for(j=0; j<cli_count; j++ )
					Write( cli_info[j], buff, ret );
			}
		}
	}
	Close(sd);
	return 0;
}

