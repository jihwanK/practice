#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include "IR.h"

int maximum = 60;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;

int main()
{
	int i;
	init_IR();
	init_motor();
	stop();
	printf(">>> Calibraing..... ");
/*	
	for(i = 0; i < 100; i++){
		printf("%d", i);
		if(i < 25 || i >=75){
			right();
			setPWMA(30);
			setPWMB(30);
		}
		else{
			left();
			setPWMA(30);
			setPWMB(30);
		}
	Calibrate();
	}
	printf("\n>>> Complete the calibration:\n");
	stop();
	printf("	Calibr. max: %d   |   Calibr. min: %d\n", calibratedMax, calibratedMin);
*/	
	printf(">>> Start line following !!!\n");
	forward();

	//while(1){
	for(int k = 0; k < 2000; k++){
		readLine();
		int position = last_value;
		
		if(sensor_values[0] > 900 && sensor_values[1] > 900 && sensor_values[2] &&
		   sensor_values[3] > 900 && sensor_values[4] > 900){
			setPWMA(0);
			setPWMA(0);
		}
		else{
			// the p term should be 0 when we are on the line
			proportional = position - 2250;
			
			// compute the d (change) and i (sum) of the position
			derivate = proportional - last_proportional;
			integral += proportional;
			
			// remember the last position
			last_proportional = proportional;

			int power_diff = proportional/10 + derivate;//  integral/10000 + derivate;

			if(power_diff > maximum)
				power_diff = maximum;
			if(power_diff < -maximum)
				power_diff = -maximum;

			printf("(%d) >> P: %d, I: %d, D: %d >> vel: %d\n", position, proportional, derivate, integral, power_diff);

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
