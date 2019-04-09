#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "socklib.h"

int main()
{
	int sd;
	int ret;
	char buff[1024];
	struct sockaddr_in addr;
	sd = Socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	Connect(sd, (struct sockaddr*)&addr, sizeof(addr));
	while( ret = read(0, buff, sizeof buff ) )
	{
		Write( sd, buff, ret);
		ret = Read( sd, buff, sizeof buff );
		Write( 1, buff, ret );
	}
	Close(sd);
	return 0;
}

