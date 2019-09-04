#include <sys/types.h>       
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int sd;
	int ret;
	char buff[1024];
	struct sockaddr_in addr;
	sd = socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	connect(sd, (struct sockaddr*)&addr, sizeof(addr));
	write( sd, "get filename", 12);
	ret = read( sd, buff, sizeof buff );
	write( 1, buff, ret );
	close(sd);
	return 0;
}
