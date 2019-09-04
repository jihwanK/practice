#include "motor_control.h"
#include <wiringPi.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "IR.h"
#include <unistd.h>
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
const int STRAIGHT = 0;
const int LEFT = 1;
const int RIGHT = 2;

int cur = 0;
int prev = 0;
int prev_prev = 0;
int state[3] = {-1, -1, -1};

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

int main(int argc, char *argv[]) {
	int i;
	int div;
	int _maximum;
	int min;
	
	old_i = signal(SIGINT, my_sig);

	_maximum = atoi(argv[1]);
	min = atoi(argv[2]);
	div = atoi(argv[3]);

	init_IR();
	init_motor();
	stop();
	printf(">>> Calibraing..... ");

	forward();
	
	while(1) {
		readLine();
		state[cur] = sensor_values[2];

		cur = (cur + 1) % 3;
//		prev = (cur - 1 < 0) ? 2 : (cur - 1);
//		prev_prev = (prev - 1 < 0) ? 2 : (prev - 1);

		// 최초 조건 -1이 하나라도 잇으면 최대속력
		if (state[0] == -1 || state[1] == -1 || state[1] == -1)
			maximum = _maximum;

		// 다같으면 최대 속력
		if (state[0] < 200 && state[1] < 200 && state[2] < 200)
			maximum = _maximum;
		else
			maximum = min;
		printf("====== maximum value %d ======= \n", maximum);
		move();
	}

	stop();

	return 0;
}
