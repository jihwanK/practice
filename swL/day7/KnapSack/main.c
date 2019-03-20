#include <stdio.h>
#include "KnapSack.h"

int main(void) {
	int T;
	int result;
	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (int tc=0 ; tc<T ; tc++) {
		initData();
		createData();
		printData();
		result = calc();
		printf("%d\n", result);
	}

	return 0;
}
