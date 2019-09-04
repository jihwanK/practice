#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <wiringPi.h>
int pin[4] = { 27,24,28,29 };
int seq[][4] = {
	{ 1,0,0,1 },
	{ 1,0,0,0 },
	{ 1,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,0 },
	{ 0,0,1,1 },
	{ 0,0,0,1 }
};
void forwards( int steps )
{
	int i,j,k;
	for(i=0; i<steps; i++ )
	{
		for(j=0; j<8; j++ )
		{
			for(k=0; k<4; k++ )
				digitalWrite( pin[k], seq[j][k] );
			delayMicroseconds(800);

		}
	}
}
void backwards( int steps )
{
	int i,j,k;
	for(i=0; i<steps; i++ )
	{
		for(j=0; j<8; j++ )
		{
			for(k=0; k<4; k++ )
				digitalWrite( pin[k], seq[8-j-1][k] );
			delayMicroseconds(800);
		}
	}
}
int main ()
{
	wiringPiSetup ()  ;
	pinMode (27, OUTPUT) ;
	pinMode (24, OUTPUT) ;
	pinMode (28, OUTPUT) ;
	pinMode (29, OUTPUT) ;
	while(1)
	{
		forwards(1024);
		delay(100);
		backwards(1024);
		delay(100);
	}
	return 0;
}

