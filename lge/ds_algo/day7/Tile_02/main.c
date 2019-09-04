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
		int m = f(n);
		printf("%d\n", m);
	}
	
	return 0;
}

int f(int n) {
	
	// TODO
	
}
