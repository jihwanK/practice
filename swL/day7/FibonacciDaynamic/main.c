#include <stdio.h>

#define MAX 100000

unsigned long long int DT[MAX + 1];
unsigned long long int f(int n);

unsigned long long int f(int n) {
	if (n <= 2) {
		DT[n] = 1;
	} else {
		if (DT[n] == 0)
			DT[n] = f(n - 2) + f(n - 1);
	}
	return DT[n];
}

int main(void) {
	long long int result;

	printf("N : Fibonacci Number\n");
	for (int i=1 ; i<90 ; i++) {
		result = f(i);
		printf("%d : %I64d\n", i, result);
	}

	return 0;
}
