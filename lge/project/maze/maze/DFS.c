#include "motor_control.h"
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include "IR.h"
#include <signal.h>
// #include "motor_control.h"
#include <stdlib.h>
#include <unistd.h>

#include "stack.h"
// #include <stdio.h>
// #include <stdlib.h>

#include "motor_control.h"
#include "IR.h"


#define LEFT 1
#define STRAIGHT 2
#define RIGHT 3

#define N_LEFT (-1)
#define N_STRAIGHT (-2)
#define N_RIGHT (-3)



void go_left(){
	for(int i = 0; i < 1040; i++){
		setMotor(-10, 10);
		delay(1);
	}
	stop();
}


void go_right(){
	for(int i = 0; i < 1040; i++){
		setMotor(10, -10);
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

int move()
{
	readLine();
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






int state;  
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

int is_dead_end() {
  return 1;
}

int is_goal() {
  return 1;
}

void set_motor_right() {
  setMotor(10, -10);
}

void set_motor_left() {
  setMotor(-10, 10);
}

char dfs(char dir) {
  // if (dir != STRAIGHT)
  //   push(&stack, dir);
  
  if (dir == LEFT || dir == N_LEFT) {
    set_motor_left();
  } else if (dir == RIGHT || dir == N_RIGHT) {
    set_motor_right();  
  }
  while(1){
    move();
    readLine();
    if()
  }

  while(state == 0);
  usleep(500000);
  stop();

  if (state == 1) { // 1: ㅓ
    push(&stack, N_LEFT);
    dfs(LEFT);
    dfs(STRAIGHT);
  } else if (state == 2) { // 2: ㅏ
    push(&stack, N_RIGHT);
    dfs(RIGHT);
    dfs(STRAIGHT);
  } else if (state == 3) { // 3: ㅜ
    push(&stack, N_LEFT);
    dfs(LEFT);
    push(&stack, N_RIGHT);
    dfs(RIGHT);
  } else if (state == 4) { // 4: +
    push(&stack, N_LEFT);
    dfs(LEFT);
    push(&stack, N_RIGHT);
    dfs(RIGHT);
    dfs(STRAIGHT);
  } else if (state == 5) { // 5: ㄱ
    push(&stack, LEFT);
    dfs(LEFT);
  } else if (state == 6) { // 6: r
    push(&stack, RIGHT);
    dfs(RIGHT);
  } else if (state == 7) { // 7: dead end
      char cur_dir;

      set_motor_right();
      set_motor_right();

      while(1) {
        forward();
        while(state == 0);
        usleep(500000);
        stop();

        pop(&stack, &cur_dir);

        if (cur_dir < 0) {
          if (cur_dir == N_LEFT) {
            set_motor_left();
            return;
          } else if (cur_dir == N_RIGHT) {
            set_motor_right();
            return;
          }
        } else {
          if (cur_dir == LEFT) {
            set_motor_right();
          } else if (cur_dir == RIGHT) {
            set_motor_left();
          } 
        }
      }
    } else if (state == 8) { // -1: goal
      return ;
    }

  return ;
}

int main()
{
  init_IR();
  init_motor();


}