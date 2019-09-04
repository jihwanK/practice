#include <stdio.h>
#include "KnapSack.h"

int dp[MAX + 1][MAX + 1];
int V[MAX + 1];
int W[MAX + 1];
int C;
int J;

void initData(void) {

	/*
	 * TO DO
	 */

	for (int i = 0; i <= MAX; i++) {
		V[i] = 0;
		W[i] = 0;

		for (int j = 0; j <= MAX; j++) {
			dp[i][j] = 0;
		}
	}
}

void createData(void) {

	/*
	 * TO DO
	 */

	scanf("%d %d", &C, &J);

	for (int i = 1; i <= C; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}
}

void printData(void) {
	int i;

	for (i=1 ; i<=C ; i++) {
		printf("%d %d\n", W[i], V[i]);
	}
}

int calc(void) {

	/*
	 * TO DO
	 */

	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= J; j++) {
			if (W[i] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - W[i]] + V[i]) ? dp[i - 1][j] : (dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}

	return dp[C][J];
}
