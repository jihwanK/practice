#include <stdio.h>
#include <wiringPi.h>

#define SEG_DIG  1
#define LED 0

int led[] = { 11,10,13,12,14,15,16,0 };
int num[10][8] = {
	{ 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 1, 1, 0, 0, 1 },
	{ 0, 1, 0, 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 1 }
};

/*
void fnd_write( int row )
{
	int i;

	for( i=0; i<8; i++ )
		digitalWrite(led[i], LOW );

	for( i=0; i<8; i++ )
		digitalWrite(led[i], !num[row][i] );
}
*/

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
			for( j=0; j<3; j++ )
				digitalWrite( SEG_DIG+j, (2-i)==j );

			for( j=0; j<8; j++ )
				digitalWrite(led[j], !num[temp][j] );

			delay(5);
			n /= 10;
			if( n == 0 )
				break;
		}
	}
}

int main()
{
	int i=0;
	wiringPiSetup ()  ;
	for(i=0; i<3; i++)
		pinMode (SEG_DIG+i, OUTPUT);
	for(i=0; i<8; i++)
		pinMode (led[i], OUTPUT);
	for(i=0; i<1000; i++)
	{
		fnd_write( i );
	}
	return 0;
}

