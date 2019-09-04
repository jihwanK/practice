#include <stdio.h>
#include "nqueen.h"

int main(void) {
/* 	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		scanf("%d", &N);
		nQueen(1);
	}
 */

	for (int i=1 ; i<=MAX_CNT ; i++) {
		N = i;
		placementCnt = 0;

		initCheck();
		nQueen(1);
		printf("N = %2d  배치 가능 경우의 수 : %d\n", N, placementCnt);
	}

	return 0;
}
