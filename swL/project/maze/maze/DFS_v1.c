#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "stack.h"
#include "motor_control.h"
#include "IR.h"
#include <pthread.h>

#define LEFT 1
#define STRAIGHT 2
#define RIGHT 3

#define N_LEFT (-1)
#define N_STRAIGHT (-2)
#define N_RIGHT (-3)

int flag = 0;

int maximum = 10;
int integral = 0;
int last_proportional = 0;
int proportional = 0;
int derivate = 0;

int binary_sensors[5];

pthread_t dynamic_state;

int state = 0;  
// 0 : moving
// 1: ㅓ
// 2: ㅏ
// 3: ㅜ
// 4: +
// 5: ㄱ
// 6: r
// 7: dead end
// 8: goal

Stack stack;
Stack result;

void turn_left() {
	//forward();
	while(1) {
		setMotor(-20, 20);
		if (state == 0) break;
	}
	stop();
}

void turn_right() {
	//forward();
	while(1) {
		setMotor(20, -20);
		if (state == 0) break;
	}
	stop();
}

void go_forward() {
	//forward();
	//for(int i = 0; i < 100; i++)
	while(1) {	
	//usleep(100);
		if (state != 0) break;
		setMotor(-13, -13);
	}
}


void delay_forward() {
	for (int i = 0; i < 200; i++) {
		//forward();
		setMotor(-10, -10);
		delay(1);
		//delay(500);
	}
}


int move() {
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


int is_dead_end() {
	return 1;
}

int is_goal() {
	return 1;
}

void print_node(char c) {
	printf("%d -- ", c);
}

void dfs(char dir) {
	int prev_state;
	
	print_stack(&stack, print_node); 
	if (dir == LEFT || dir == N_LEFT) {
		turn_left();
	} else if (dir == RIGHT || dir == N_RIGHT) {
		turn_right();  
	}

	forward();
	while(state == 0) {
		//printf("working \n");
		// if (state == 2 || state == 3 || state == 4 || state == 5 || state == 6 || state == 7) break;
		move();
	}

	prev_state = state;

	if (prev_state == 3) {
		printf("state 3 \n");
		stop();
		delay_forward();

		if (state == 0) {
			prev_state = 4;
		}
	} else if (prev_state == 5) {
		printf("state 5 \n");
		stop();
		delay_forward();

		if (state == 0) {
			prev_state = 1;
		}
	} else if (prev_state == 6) {
		printf("state 6 \n");
		stop();
		delay_forward();

		if (state == 0) {
			prev_state = 2;
		}
	} else if (prev_state == 0) {
		stop();
		delay_forward();

		if (state == 7) {
			prev_state = 7;
		}
	} else if (prev_state == 3) {
		stop();
		delay_forward();

		if (state == 7) {
			prev_state = 3;
		}
	}

	if (prev_state == 1) { // 1: ㅓ
		//printf("ㅓ \n");
		push(&stack, N_LEFT);
		dfs(LEFT);
		dfs(STRAIGHT);
	} else if (prev_state == 2) { // 2: ㅏ
		//printf("ㅏ \n");
		push(&stack, N_RIGHT);
		dfs(RIGHT);
		dfs(STRAIGHT);
	} else if (prev_state == 3) { // 3: ㅜ
		//printf("ㅜ \n");
		push(&stack, N_LEFT);
		dfs(LEFT);
		push(&stack, N_RIGHT);
		dfs(RIGHT);
	} else if (prev_state == 4) { // 4: +
		//printf("+ \n");
		push(&stack, N_LEFT);
		dfs(LEFT);
		push(&stack, N_RIGHT);
		dfs(RIGHT);
		dfs(STRAIGHT);
	} else if (prev_state == 5) { // 5: ㄱ
		//printf("ㄱ \n");
		push(&stack, LEFT);
		dfs(LEFT);
	} else if (prev_state == 6) { // 6: r
		//printf("r \n");
		push(&stack, RIGHT);
		dfs(RIGHT);
	} else if (prev_state == 7) { // 7: dead end
		//printf("dead end \n");
		char cur_dir;

		turn_right();

		while(1) {
			go_forward();

			while(state == 0) {
				move();
			}

			stop();
			delay_forward();

			prev_state = state;

			pop(&stack, &cur_dir);

			if (cur_dir < 0) {
				if (cur_dir == N_LEFT) {
					turn_left();
					return;
				} else if (cur_dir == N_RIGHT) {
					turn_right();
					return;
				}
			} else {
				if (cur_dir == LEFT) {
					turn_right();
				} else if (cur_dir == RIGHT) {
					turn_left();
				} 
			}
		}
	} else if (prev_state == 8) { // -1: goal
		return ;
	}

	return ;
}


void best_path() {
	char tmp;
	while(!is_stack_empty(&stack)) {
		pop(&stack, &tmp);
		push(&result, tmp);
	}
}


void convert_into_b_sensor () {
	for (int i = 0; i < 5; i++) {
		if (sensor_values[i] < 300) {
			binary_sensors[i] = 1;
		} else {
			binary_sensors[i] = 0;
		}
	}
}

void print_sensor() {
	for (int i = 0; i < 5; i++) {
		printf("%d ", sensor_values[i]);
	}
	printf("\n");
}

void print_b_sensor() {
	for (int i = 0; i < 5; i++) {
		printf("%d ", binary_sensors[i]);
	}
	printf("\n");
}

void *update_state(void* data) {
	pthread_detach(pthread_self());
	int left, right, straight;

	while(1) {
		readLine();
		convert_into_b_sensor();

		printf("state: %d \n", state);

		// convert into state
		left = binary_sensors[0];
		right = binary_sensors[4];
		straight = binary_sensors[1] || binary_sensors[2] || binary_sensors[3];

		if (left == 1 && right == 0 && straight == 1) {
			if(state == 3)
				continue;
			state = 5;
		} else if (left == 0 && right == 1 && straight == 1) {
			if(state == 3)
				continue;
			state = 6;
		} else if (left == 0 && right == 0 && straight == 1) {
			state = 0;
		} else if (left == 1 && right == 1 && straight == 1) {
			state = 3;
		} else if (left == 0 && right == 0 & straight == 0) {
			state = 7;
		}

		usleep(50000);
	}
	// pthread_exit(NULL);
}

int main() {
	state = 0;
	init_IR();
	init_motor();

	pthread_create(&dynamic_state, NULL, update_state, NULL);

	init_stack(&stack);

	/*
		 while(1) {
	//readLine();
	//convert_into_b_sensor();

	usleep(50000);

	printf("state: %d \n", state);

	print_sensor();
	print_b_sensor();
	}
	 */
	//delay_forward();
	dfs(STRAIGHT);

	//	stop();
	//		turn_left();
	//		turn_left();

	return 0;
}
