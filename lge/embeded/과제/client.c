#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <wiringPi.h>
#include <mcp3422.h>


double celsius;
int cds;

void get_value()
{
	celsius = ((analogRead(401) / 1000.0) - 0.5) * 100;
	cds = analogRead(400);
}

int main()
{
	int sd; //socke_discriptor
	struct sockaddr_in addr;
	char buff[1024];
	int ret;

	int menu;

	const int TEMP = 1;
	const int CDS = 2;
	int length;
	
	/* setup the raspberry pi */
	if (wiringPiSetup() == -1)
		return ;

	mcp3422Setup(400, 0x6a, 0, 0);
	/* finish setup */

	sd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(7777);
	addr.sin_addr.s_addr    = inet_addr("192.168.137.100");

	connect(sd, (struct sockaddr*)&addr, sizeof(addr));

	while(1)
	{
		get_value();

		write(sd, &TEMP, sizeof(TEMP));
		write(sd, &length, sizeof(length));
		write(sd, &celsius, sizeof(celsius));

		write(sd, &CDS, sizeof(CDS));
		write(sd, &length, sizeof(length));
		write(sd, &cds, sizeof(cds));

		sleep(3000);
	}

	close(sd);
}
