#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>
#include <mcp3422.h>

#define SW_1 (4)
#define SW_2 (5)

#define LED (27)
#define GET_TEMP (1)
#define R_GET_TEMP (2)

int leds[] = {27, 24, 28, 29};


/*

	 readn(sd, &type, length
	 switch(type)
	 {
	 case R_GET_TEMP:
	 readn(sd, &len, 4);
	 readn(sd, &temp, len);

	 }

 */


void led_on(int ratio)
{
	int i;
	int limit = ratio / 512;

	for (int i = 0; i < 4; i++)
	{
		if (i <= limit)
			digitalWrite(leds[i], HIGH);
		else 
			digitalWrite(leds[i], LOW);
	}
}


int main()
{
	int read_temp;
	int read_light;
	int read_variable;

	wiringPiSetup();
	mcp3422Setup(400, 0x6a, 0, 0);

	for (int i = 0; i < 4; i++)
	{
		pinMode(leds[i], OUTPUT);
		digitalWrite(leds[i], LOW);
	}

	while(1) 
	{
		double volt = 0;
		double celsius = 0;

		read_light = analogRead(400);
		read_temp = analogRead(401);
		read_variable = analogRead(403);

		volt = read_temp / 1000.0;
		celsius = (volt - 0.5) * 100;

		if (read_light > 500)
			digitalWrite(LED, HIGH);
		else
			digitalWrite(LED, LOW);

		printf("darkness=%d, volatage=%5.2lf, temp=%5.2lf, variable=%d\n", read_light, volt, celsius, read_variable);
		printf("%d \n", read_temp);
		led_on(read_variable);

	}

	return 0;
}







