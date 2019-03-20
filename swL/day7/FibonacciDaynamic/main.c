#include <stdio.h>
#define MAX 100000

unsigned long long int DT[MAX + 1];
unsigned long long int f(int n);

unsigned long long int f(int n) {

	/*
	 * TO DO
	 */

	return 0;
}

int main(void) {
	long long int result;

	printf("N : Fibonacci Number\n");
	for (int i=1 ; i<50 ; i++) {
		result = f(i);
		printf("%d : %I64d\n", i, result);
	}

	return 0;
}
