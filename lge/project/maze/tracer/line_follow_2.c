#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "IR.h"

int maximum = 0;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;
int right_first = 0;
int left_first = 0;

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

	maximum = atoi(argv[1]);
	div = atoi(argv[2]);

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
	int turning_left = 0;
	int turning_right = 0;
	int straight = 0;

	//while(1){
	for(int k = 0; k < 2400; k++){
		readLine();
		int position = last_value;
		
		if(sensor_values[0] > 900 && sensor_values[1] > 900 && sensor_values[2] &&
		   sensor_values[3] > 900 && sensor_values[4] > 900){
			setPWMA(0);
			setPWMA(0);
		}
		else{
			// the p term should be 0 when we are on the line
			proportional = position - 1800;
			
			// compute the d (change) and i (sum) of the position
			derivate = proportional - last_proportional;
			integral += proportional;
			
			// remember the last position
			last_proportional = proportional;
			
			/*	
			if((sensor_values[4] < 300 && sensor_values[2] < 300) && turning_right == 0){
				turning_right = 1;
				printf("----------------- turning right start -----------------------\n");
			}else if((sensor_values[4] < 300 && sensor_values[2] < 300) && turning_right == 1
					&& right_first > 7){
				turning_right = 0;
				printf("------------------ turning right finish -----------------------\n");
			}else if (sensor_values[0] < 300 && sensor_values[2] < 300 && turning_right == 1 
					&& turning_left == 0 && right_first > 7){
				turning_right = 0;
				turning_left = 1;
				printf("-------------------  right -> left  ---------------------------\n");
			}
			
			else if((sensor_values[0] < 300 && sensor_values[2] < 300) && turning_left == 0){
				turning_left = 1;
				printf("----------------  turning left start ---------------------------\n");
			}else if((sensor_values[0] < 300 && sensor_values[2] < 300) && turning_left == 1
					&& left_first > 7){
				turning_left = 0;
				printf("--------------------- turning left finish -------------------------\n");
			}else if(sensor_values[4] < 300 && sensor_values[2] < 300 && turning_left == 1 
					&& turning_right == 0 && left_first > 7){
				turning_left = 0;
				turning_right = 1;
				printf("---------------------- left -> right -----------------------------\n");
			}

			if(turning_left == 1 || turning_right == 1){
				maximum = 60;
				if(turning_left)
					left_first++;
				if(turning_right)
					right_first++;
			}
			else{
				maximum = 100;
				if(!turning_left)
					left_first = 0;
				if(!turning_right)
					right_first = 0;
			}
			*/
			int power_diff = proportional/div + derivate;//  integral/10000 + derivate;
		/*	

			if(sensor_values[2] < 300 && sensor_values[0] > 500 && sensor_values[1] > 400 &&
					sensor_values[3] > 400 && sensor_values[4] > 500)
				maximum = 65 ;
			//	power_diff /= ;
			else 
				maximum = 65;
			//	power_diff = power_diff;
*/
			
			//if(sensor_values[
			if(power_diff > maximum)
				power_diff = maximum;
			if(power_diff < -maximum)
				power_diff = -maximum;

			printf("(%d) >> P: %d, I: %d, D: %d >> vel: %d >>> t: %d, %d >> %d %d %d %d %d >>> M: %d\n",
					position, proportional, derivate, integral, power_diff, turning_left, turning_right,
					sensor_values[0], sensor_values[1], sensor_values[2], sensor_values[3], sensor_values[4], maximum);

			if(power_diff < 0){
				setPWMA(maximum + power_diff);
				setPWMB(maximum);
				//setPWMA(0); setPWMB(0);
			}
			else{
				setPWMA(maximum);
				setPWMB(maximum - power_diff);
				//setPWMA(0); setPWMB(0);
			}
		}
	}
	stop();

	return 0;
}
