#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>

int main (void)
{
	int bright ;

	printf ("Raspberry Pi wiringPi PWM test program\n") ;

	if (wiringPiSetup () == -1)
		exit (1) ;

	pinMode (23, PWM_OUTPUT) ;
	pwmWrite (23, 0) ;
	for (;;)
	{
		for (bright = 0 ; bright < 1024 ; ++bright)
		{
			pwmWrite (23, bright) ;
			delay (1) ;
		}

		for (bright = 1023 ; bright >= 0 ; --bright)
		{
			pwmWrite (23, bright) ;
			delay (1) ;
		}
	}

	return 0 ;
}

