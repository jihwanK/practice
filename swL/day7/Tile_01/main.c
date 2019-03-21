#include <stdio.h>

int f(int n);

int main(void) {
	int T;
	int n;
	int tc;
	
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc=0 ; tc<T ; tc++) {
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	
	return 0;
}

int f(int n) {
	
	// TODO
	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 2;
	}

	if (n % 2 == 0) {
		
	} else {

	}

}
