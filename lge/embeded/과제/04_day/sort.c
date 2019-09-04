#include <stdio.h>
#define MAX_SERVOS 8
//int myDelays[8] = { 4,3,5,2,6,1,8,7 };
//int myPins[8] = {20,24,25,11,12,32,26,15};
int myDelays[8] = { 1500,1500,1500,1500,1500,1500,1500,1500 };
int myPins[8] = {25,-1,-1,-1,-1,-1,-1,-1};
void foo(void)
{
	int m, j, i, k, tmp;
	for (m = MAX_SERVOS / 2 ; m > 0 ; m /= 2 )
		for (j = m ; j < MAX_SERVOS ; ++j)
			for (i = j - m ; i >= 0 ; i -= m)
			{
				k = i + m ;
				if (myDelays [k] >= myDelays [i])
					break ;
				else // Swap
				{
					tmp = myDelays [i] ; myDelays [i] = myDelays [k] ; myDelays [k] = tmp ;
					tmp = myPins   [i] ; myPins   [i] = myPins   [k] ; myPins   [k] = tmp ;
				}
			}
}

int main()
{
	int i;
	for(i=0; i<8; i++ )
	{
		printf("(%d,%d)\n", myDelays[i], myPins[i] );
	}
	printf("------------\n");
	foo();
	for(i=0; i<8; i++ )
	{
		printf("(%d,%d)\n", myDelays[i], myPins[i] );
	}
	return 0;
}








