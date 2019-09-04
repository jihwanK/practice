#include "motor_control.h"
#include <wiringPi.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "IR.h"

int maximum = 50;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;
int right_first = 0;
int left_first = 0;

typedef void (*handler_t)(int);

handler_t signal(int, handler_t);
handler_t old_i;
pthread_t threads;

int is_curve = 0;
int state;
const int STRAIGHT = 0;
const int LEFT = 1;
const int RIGHT = 2;

void *update_state(void* data) {
	pthread_detach(pthread_self());

	while(1) {
		readLine();
		usleep(50000);
	}
}

void my_sig(int signo)
{
	if (signo == SIGINT) {
		stop();
		exit(0);
	}
}

int move() {
	int position = last_value;

	// the p term should be 0 when we are on the line
	proportional = position - 1800;

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

	if(power_diff < 0) {
		setPWMA(maximum + power_diff);
		setPWMB(maximum);
	}
	else {
		setPWMA(maximum);
		setPWMB(maximum - power_diff);
	}
	return 0;
}

void check_curve() {
	if (sensor_values[0] < 200) {
		// left curve starts
		if (is_curve == STRAIGHT)
			is_curve = LEFT;
		else if (is_curve == LEFT)
			is_curve = STRAIGHT;
		else if (is_curve == RIGHT)
			is_curve = RIGHT;
	} else if (sensor_values[4] < 200) {
		// left curve starts
		if (is_curve == STRAIGHT)
			is_curve = RIGHT;
		else if (is_curve == RIGHT)
			is_curve = STRAIGHT;
		else if (is_curve == LEFT)
			is_curve = LEFT;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int div;
	pthread_create(&threads, NULL, update_state, NULL);
	
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
	while(1){
	
		int position = last_value;
		
		if(sensor_values[0] > 900 && sensor_values[1] > 900 && sensor_values[2] &&
		   sensor_values[3] > 900 && sensor_values[4] > 900){
			setPWMA(0);
		}
		else{
			move();
		}
	}
	stop();

	return 0;
}
