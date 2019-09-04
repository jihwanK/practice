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

void *my_handler( void *data )
{
	char buff[1024];
	int ret;
	int new_sd;
	int i;

	pthread_detach(pthread_self()); // thread의 분리 코드
	new_sd = (int)data;
	while(1)
	{
		ret = Read( new_sd, buff, sizeof buff );
		if( ret == 0 )
		{
			for( i=0; i<cli_count; i++ )	
				if( cli_info[i] == new_sd )
					break;
			cli_count--;
			if( i != cli_count )
				cli_info[i] = cli_info[cli_count];

			printf("연결이 정상 종료 되었습니다., 현재 접속자 수 : %d\n",
					cli_count);
			break;
		}
		Write( 1, buff, ret );
		for(i=0; i<cli_count; i++ )
			Write( cli_info[i], buff, ret );
	}
	Close(new_sd);
	return 0;
}
int main()
{
    int sd, new_sd;
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
		addrlen = sizeof( cli_addr );
		new_sd = Accept(sd, (struct sockaddr*)&cli_addr, &addrlen);
		cli_info[cli_count++] = new_sd;
		printf("client ip=%s, port=%d, 현재 접속자 수 : %d명\n", 
				inet_ntoa(cli_addr.sin_addr),
				ntohs(cli_addr.sin_port), cli_count);
		pthread_create( &thread, 0, my_handler, (void*)new_sd );
	}
	Close(sd);
	return 0;
}

