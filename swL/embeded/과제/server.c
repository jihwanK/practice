#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <pthread.h>
#include <wiringPi.h>
#include <mcp3422.h>
#include <softServo.h>
#include <softPwm.h>

//#include "myprotocol.h"


#define LED 0
#define SEG_DIG 1


#define SW_1 4
#define SW_2 5


typedef struct {
	int type;
	int length;
	char *data;
} MY_PROTOCOL;

int led[] = {11, 10, 13, 12, 14, 15, 16, 0};
int num[10] = { 0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09 };
static int fnd_value=0;

//int num[10][8] = {
//	{0, 0, 0, 0, 0, 0, 1, 1},
//	{1, 0, 0, 1, 1, 1, 1, 1},
//	{0, 0, 1, 0, 0, 1, 0, 1},
//	{0, 0, 0, 0, 1, 1, 1, 1},
//	{1, 0, 0, 1, 1, 0, 0, 1},
//	{0, 1, 0, 0, 1, 0, 0, 1},
//	{0, 1, 0, 0, 0, 0, 0, 1},
//	{0, 0, 0, 1, 1, 1, 1, 1},
//	{0, 0, 0, 0, 0, 0, 0, 1},
//	{0, 0, 0, 0, 1, 0, 0, 1}
//};


ssize_t readn(int fd, void *vptr, size_t n);

void create_packet(MY_PROTOCOL *prot, int type, int length);
int get_type_head(MY_PROTOCOL *prot);
int get_length_head(MY_PROTOCOL *prot);
char *get_data(MY_PROTOCOL *prot);


int raspberry();
double get_temp();
int get_cds();
int check_cds_setp();
int check_temp_servo();
void fnd_write(int row);
void show_digit(int index, int n);
void *fnd_thread(void* data);


void create_packet(MY_PROTOCOL *prot, int type, int length)
{
	prot->type = type;
	prot->length = length;
	prot->data = malloc(sizeof(char) * length);
}

/////////////////////////////////////////////////////////////

int get_type_head(MY_PROTOCOL *prot)
{
	return prot->type;
}

int get_length_head(MY_PROTOCOL *prot)
{
	return prot->length;
}

char *get_data(MY_PROTOCOL *prot)
{
	return prot->data;
}

/////////////////////////////////////////////////////////////




ssize_t readn(int fd, void *vptr, size_t n)
{
	size_t  nleft;
	ssize_t nread;
	char   *ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ( (nread = read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0;      /* and call read() again */
			else
				return (-1);
		} else if (nread == 0)
			break;              /* EOF */

		nleft -= nread;
		ptr += nread;
	}
	return (n - nleft);         /* return >= 0 */
}



/////////////////////////////////////////////////////////////


int raspberry()
{
	if (wiringPiSetup() == -1)
		return -1;

	mcp3422Setup(400, 0x6a, 0, 0);
	pinMode(SW_1, INPUT);
	pinMode(SW_2, INPUT);


	while(1)
	{
		if (digitalRead(SW_1) == LOW)
		{
			printf("current temperature is %lf \n", get_temp());
			//fnd_write(9);
			fnd_value = (int)get_temp();
		} 
		//else
	//	{
	//		fnd_value = (int)0;
//		}

		if (digitalRead(SW_2) == LOW)
		{
			printf("current lighting scale is %d \n", get_cds());
			fnd_value = (int)get_cds();
		}
//		else
//		{
//			fnd_value = (int)0;
//		}

		check_temp_servo();
		//check_cds_setp();
	}
}


void show_digit( int index, int n )
{
	int i;
	for( i=0; i<3; i++ )
		digitalWrite( SEG_DIG+i, (2-index)==i );

	for( i=0; i<8; i++ )
		digitalWrite(led[i], !(num[n]&(1<<(7-i))) );
}

void fnd_write( int row )
{
	int i,j,k;
	int n,temp;
	for(k=0; k<60; k++ )
	{
		n = row;
		for(i=0; i<3; i++ )
		{
			temp = n%10;
			show_digit( i, temp );
			delay(2);
			n /= 10;
			if( n == 0 )
				break;
		}
	}
}

void *fnd_thread(void* data)
{
	int i=0;

	pthread_detach(pthread_self());

	for(i=0; i<3; i++)
		pinMode(SEG_DIG+i, OUTPUT);

	for(i=0; i<8; i++)
		pinMode (led[i], OUTPUT);

	while(1)
	{
		fnd_write( fnd_value );
	}
	return 0;
}



double get_temp()
{
	int read_temp = analogRead(401);
	double volt = read_temp / 1000.0;
	double celsius = (volt - 0.5) * 100;

	return celsius;
}

int get_cds()
{
	return analogRead(400);
}

int check_cds_setp()
{
	if (get_cds() < 1024)
	{
		printf("over 1024 \n"); //clockwise
	}
	else 
	{
		printf("within 1024\n"); // counter-clockwise
	}
}

int check_temp_servo()
{
	softServoSetup(25, -1, -1, -1, -1, -1, -1, -1);

	if(get_temp() < 25)
	{
		softServoWrite(25, 0);
		delay(500);
		softServoWrite(25, 800);
		delay(500);

	}
}

int check_sw1_temp()
{
	if (digitalRead(SW_1) == LOW)
	{
		get_temp();
	}
}




/////////////////////////////////////////////////////////////


void init_server()
{

}


/////////////////////////////////////////////////////////////

int main()
{
	/* variables start */

	MY_PROTOCOL prot;
	pthread_t thread;
	pthread_create(&thread, 0, fnd_thread, 0);

	int len;
	char buf[1024];

	struct sockaddr_in saddr = {0, };
	struct sockaddr_in caddr = {0,};
	socklen_t socklen = sizeof caddr;

	int ssock = socket(PF_INET, SOCK_STREAM, 0);
	int csock;

	/* variables end */

	
	raspberry();



	if (ssock == -1)
	{
		perror("socket");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(5000);
	saddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(ssock, (struct sockaddr*)&saddr, sizeof saddr) < 0)
	{
		perror("bind");
		return -1;
	}

	if (listen(ssock, SOMAXCONN) < 0)
	{
		perror("listen");
		return -1;
	}

	csock = accept(ssock, (struct sockaddr*)&caddr, &socklen);

	if(csock != -1)
	{
		char* cip = inet_ntoa(caddr.sin_addr);
		printf("client: ip: %s \n", cip);
	}

	while(1)
	{
		len = read(csock, buf, sizeof(buf));
		if (len == 0)
		{
			printf("connection terminates\n");
			break;
		}
		else if (len == -1)
		{
			perror("read");
			break;
		}

		printf("len: %d \n", len);
	}

	close(csock);
	close(ssock);

	return 0;
}
