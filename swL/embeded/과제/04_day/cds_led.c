#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>
#include <mcp3422.h>

#define LED 27

int main (int argc, char *argv [])
{
	int cds;
	wiringPiSetup () ;
	mcp3422Setup (400, 0x6a, 0, 0) ;
	pinMode (LED, OUTPUT) ;

	for (;;)
	{
		cds = analogRead (400);
		printf ("%4d\n",   analogRead (400));
		if( cds > 500 )
			digitalWrite (LED, HIGH) ;  // On
		else
			digitalWrite (LED, LOW) ;   // Off
		delay (1000) ;
	}
}

