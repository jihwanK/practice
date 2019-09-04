#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "IR.h"

int maximum = 70;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;

typedef void (*handler_t)(int);

handler_t signal(int, handler_t);
handler_t old_i;

void my_sig(int signo)
{
	if (signo == SIGINT) {
		stop();
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	int i;
	int div;

	old_i = signal(SIGINT, my_sig);

	init_IR();
	init_motor();
	stop();
	printf(">>> Start line following !!!\n");
	forward();
	
	while(1){
		readLine();
		int position = last_value;
		
		if(sensor_values[0] > 900 && sensor_values[1] > 900 && sensor_values[2] &&
		   sensor_values[3] > 900 && sensor_values[4] > 900){
			setPWMA(0);
			setPWMA(0);
		}
		else{
			proportional = position - 1850;
			derivate = proportional - last_proportional;
			integral += proportional;
			last_proportional = proportional;
			
			int power_diff = proportional/15 + derivate*2.7 +  integral/10000;// + derivate;
			//power_diff *= 1.2;
			if(power_diff > maximum)
				power_diff = maximum;
			if(power_diff < -maximum)
				power_diff = -maximum;

			printf("(%d) >> P: %d, I: %d, D: %d >> vel: %d >> %d %d %d %d %d >>> M: %d\n",
					position, proportional, integral, derivate, power_diff,
					sensor_values[0], sensor_values[1], sensor_values[2], sensor_values[3], sensor_values[4], maximum);

			if(power_diff < 0){
				setPWMA(maximum + power_diff);
				setPWMB(maximum);
			}
			else{
				setPWMA(maximum);
				setPWMB(maximum - power_diff);
			}
		}
	}
	stop();

	return 0;
}
