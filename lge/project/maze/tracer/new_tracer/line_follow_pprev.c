#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include "IR.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int mode = 1;
/*
	 mode = 1: check the state 
	 mode = 0: not check
*/
const int straight_vel = 85;
const int curve_vel = 57;
const int straight_delay = 5;
int straight_idx = 0;

int maximum;
int pppppprevalue = 0;
int ppppprevalue = 0;
int pppprevalue = 0;
int ppprevalue = 0;
int pprevalue = 0;
int prevalue = 0;
int value = 0;

int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;
int power_diff = 0;

void *chatchint(int signo){
	stop();
	delay(10);
	exit(1);
}


int main()
{
	int i;
	init_IR();
	init_motor();
	signal(SIGINT, (void *)chatchint); 
	stop();

	printf(">>> Start line following !!!\n");
	forward();
	int straight = 0;
	int a,b,c,d,e;

	while(1){
		readLine();
		pppppprevalue = ppppprevalue;
		ppppprevalue = pppprevalue;
		pppprevalue = ppprevalue;
		ppprevalue = pprevalue;
		pprevalue = prevalue;
		prevalue = value;

		int position = last_value;

		a = sensor_values[0] < 300 ? 1:0; b = sensor_values[1] < 300 ? 1:0;
		c = sensor_values[2] < 300 ? 1:0; d = sensor_values[3] < 300 ? 1:0;
		e = sensor_values[4] < 300 ? 1:0;

		if( !a && !b && c && !d && !e)
			value =1;
		else 
			value =0;


		proportional = position - 1650;
		derivate = proportional - last_proportional;
		integral += proportional;
		last_proportional = proportional;
		
		if((value == 0 && prevalue== 1 && pprevalue == 1 && ppprevalue == 1
					&& pppprevalue == 1 && ppppprevalue == 1 && pppppprevalue == 1
					) && mode == 1){
			stop();
			delay(1);
			printf("/n----------------------------------------------------------------------\n");
		}
		if((value == 1 && prevalue== 1 && pprevalue == 1 && ppprevalue == 1
					&& pppprevalue == 1// && ppppprevalue == 1 && pppppprevalue == 1
					) && mode == 1){
				maximum = straight_vel;
				power_diff = proportional/25 + derivate*2 + integral/10000;
//				power_diff *= 0.7;
				straight_idx++;
/*				if(straight_idx > straight_delay){
					maximum = curve_vel;
					value = 0;
					printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
				}*/
				printf("******************");
		}
		else{
			//backward();
			//delay(1);
			straight_idx = 0;
			maximum = curve_vel;
			power_diff = proportional/15 + derivate*3 + integral/10000;
			//power_diff *= 0.7;
		}

		printf("max: %d >> P: %d, I: %d, D: %d >> power_diff: %d >> %d %d %d %d %d %d\n", maximum, 
					proportional, integral, derivate, power_diff,
					sensor_values[0], sensor_values[1], sensor_values[2], sensor_values[3], sensor_values[4]);


		if(power_diff > maximum)
			power_diff = maximum;
		if(power_diff < -maximum)
			power_diff = -maximum;
		
		forward();
		if(power_diff < 0){
			setPWMA(maximum + power_diff);
			setPWMB(maximum);
		}
		else{
			setPWMA(maximum);
			setPWMB(maximum - power_diff);
		}
	}
	stop();

	return 0;
}
