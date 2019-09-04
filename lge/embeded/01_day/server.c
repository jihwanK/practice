#include <sys/types.h>       
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int sd, new_sd;
	int ret;
	char buff[1024];
	struct sockaddr_in addr;
	sd = socket( AF_INET, SOCK_STREAM , 0 );
	memset( &addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr   = inet_addr("192.168.137.100");
	bind(sd, (struct sockaddr*)&addr, sizeof(addr));
	listen(sd, 20);
	new_sd = accept(sd, 0, 0);
	ret = read( new_sd, buff, sizeof buff );
	write( new_sd, "hello", 5 );
	close(new_sd);
	close(sd);
	return 0;
}
