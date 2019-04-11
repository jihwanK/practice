#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <softServo.h>

int main ()
{
	int i;
	if (wiringPiSetup () == -1)
	{
		fprintf (stdout, "oops: %s\n", strerror (errno)) ;
		return 1 ;
	}

	softServoSetup (25, -1,-1,-1,-1,-1,-1,-1);
	for (i=500; i<=2400; i++)
	{
		softServoWrite (25, i) ;
		delay(1) ;
	}
}

