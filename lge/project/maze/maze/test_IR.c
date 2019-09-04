#include "IR.h"
#include <wiringPi.h>
#include <stdio.h>

int main()
{
	init_IR();
	
	while(1){
		readLine();
		printf("%d %d %d %d %d\n", sensor_values[0], sensor_values[1], sensor_values[2],
			sensor_values[3], sensor_values[4]);
	}
	return 0;
}


