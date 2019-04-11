#include <errno.h>
#include <string.h>
#include <wiringPi.h>
#include <softPwm.h>

int main ()
{
	int i;

	wiringPiSetup ()  ;

	pinMode (23, PWM_OUTPUT) ;
	pinMode (26, PWM_OUTPUT) ;
	pinMode (22, OUTPUT) ;
	pwmWrite (26, 0) ;
	pwmWrite (23, 0) ;
	softPwmCreate (22, 0, 1024) ;

	softPwmWrite (22, 0) ;
	while(1)
	{
		for (i=0;i<1024;i++)
		{
			softPwmWrite (22, i) ;
			delay(1);
		}
		for (i=1024;i>=0;i--)
		{
			softPwmWrite (22, i) ;
			delay(1);
		}
	}
	return 0;
}

