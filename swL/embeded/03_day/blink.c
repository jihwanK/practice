#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 27 is BCM_GPIO 16.

#define	LED  27	

int main (void)
{
	printf ("Raspberry Pi blink\n") ;

	wiringPiSetup () ;
	pinMode (LED, OUTPUT) ;

	for (;;)
	{
		digitalWrite (LED, HIGH) ;	// On
		delay (500) ;		        // mS
		digitalWrite (LED, LOW) ;	// Off
		delay (500) ;
	}
	return 0 ;
}

