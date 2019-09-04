#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <softServo.h>

int main()
{
	if (wiringPiSetup() == -1)
	{
		fprintf(stdout, "opps: %s \n", strerror(errno));
		return 1;
	}

	softServoSetup(25, -1, -1, -1, -1, -1, -1, -1);

	while(1)
	{
		softServoWrite(25, 0);
		delay(500);
		softServoWrite(25, -250);
		delay(500);
		softServoWrite(25, 500);
		delay(500);
		softServoWrite(25, 1250);
		delay(500);
	}
	return 0;
}
