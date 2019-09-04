#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include "IR.h"
#include <signal.h>
#include "motor_control.h"
#include <stdlib.h>
#include <unistd.h>

int maximum = 20;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;

int path[100] = {0, };
int idx = 0;
/*
left = 0;
right = 1;
back = 3;
*/

void *chatchint(int signo){
	//softPwmWrite(ENA, 0);
	//softPwmWrite(ENB, 0);
	stop();
	delay(10);
	for(int i = 0; i < idx; i++)
		printf("%3d", path[i]);
	printf("CLOSE the program .....!!!!!\n");
	exit(1);
}

int move()
{
	int position = last_value;

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

//	printf("(%d) >> P: %d, I: %d, D: %d >> vel: %d\n", position, proportional, derivate, integral, power_diff);

	if(power_diff < 0){
		setPWMA(maximum + power_diff);
		setPWMB(maximum);
	}
	else{
		setPWMA(maximum);
		setPWMB(maximum - power_diff);
	}

	return 0;
}

void go_left(){
	for(int i = 0; i < 1040; i++){
		setMotor(-10, 10);
		delay(1);
	}
	stop();
}

void go_forward(){
	for(int i = 0; i < 400; i++){
		setMotor(-10, -10);
		delay(1);
	}
	stop();
}

int main(){
	int i, cnt = 0;
	init_IR();
	init_motor();
	signal(SIGINT, (void*)chatchint);	

	while(1){
		printf("%d\n", cnt++);
		forward();
		move();
		readLine();
		printf("%d  %d  %d  %d  %d\n", sensor_values[0], sensor_values[1], 
				sensor_values[2], sensor_values[3], sensor_values[4]);
		
		if(sensor_values[4] < 400 && sensor_values[0] < 400){
			path[idx++] = 0;
			for(int j = 0; j < idx; j++)
				printf("%3d ", path[j]);
			printf("\n");
			getchar();
			printf(">> go left \n");
			stop();
			delay(500);
			go_forward();
			go_left();
			printf(" >>>> finishie going left --------\n");
		}
		
		//getchar();
		if(sensor_values [0] > 800 && sensor_values[1] > 800 && sensor_values[2] > 800 
				&& sensor_values[3] > 700 && sensor_values[4] > 600){
			printf("----- 회전 -----\n");
			stop();
			delay(500);
		
			while(1){
				readLine();
				if(sensor_values[2] < 400){
					break;
				}
				setMotor(-10, 10);
				delay(1);
			}
			path[idx++] = 3;
			for(int j = 0; j < idx; j++)
				printf("%3d ", path[j]);
			printf("\n");
			getchar();
		}

		/*
		if(sensor_values[0] > 600 && sensor_values[1] > 500 && sensor_values[2] < 300 
			&& sensor_values[3] < 400 && sensor_values[4] < 400){
			for(i = 0; i < 700; i ++){
				move();
				delay(1);
			}
			for(i = 0; i < 10; i++){
				setMotor(10, -20);
				delay(1);
			}
		}
		*/
	}
	stop();
	
	return 0;
}

