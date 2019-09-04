#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>
#include <mcp3422.h>

#define SEG_DIG  1
#define LED 0

int led[] = { 11,10,13,12,14,15,16,0 };
int num[10] = { 0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09 };

static int fnd_value=0;

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

int main()
{
	pthread_t thread;
	wiringPiSetup ()  ;
	pthread_create( &thread, 0, fnd_thread, 0 );
	mcp3422Setup (400, 0x6a, 0, 0) ;

	for (;;)
	{
		int reading = analogRead(401);  // 센서로 부터 자료값을 받는다.
		double voltage = reading/1000.;
		double celsiustemp = (voltage-0.5)*100;
		fnd_value = (int)(celsiustemp+0.5);
		delay (1000) ;
	}
	return 0;
}

