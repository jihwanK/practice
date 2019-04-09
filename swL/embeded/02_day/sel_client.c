#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/select.h>
#include "socklib.h"

int main()
{
	int sd;
	int ret;
	fd_set readfds;
	char buff[1024];
	struct sockaddr_in addr;
	sd = Socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	Connect(sd, (struct sockaddr*)&addr, sizeof(addr));
	while(1) 
	{
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(sd, &readfds);
		select( sd+1, &readfds, 0,0,0);
		if( FD_ISSET( 0, &readfds) )
		{
			ret = Read(0, buff, sizeof buff  );
			if( ret > 0 )
			{
				Write( sd, buff, ret);
			}
			else
			{
				break;
			}
		}
		if( FD_ISSET( sd, &readfds) )
		{
			ret = Read( sd, buff, sizeof buff );
			Write( 1, buff, ret );
		}
	}
	Close(sd);
	return 0;
}

