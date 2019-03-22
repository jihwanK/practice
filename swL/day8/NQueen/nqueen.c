#include <stdio.h>
#include "nqueen.h"

check_t columnChk[MAX_CNT + 1];					/* 컬럼 체크 배열 */
check_t incDiagonalLineChk[(MAX_CNT * 2) + 1];	/* 대각선 체크 */
check_t decDiagonalLineChk[(MAX_CNT * 2) + 1];	/* 대각선 체크 */
int placementCnt;								/* 배치 가능 수 카운터 */
int N;											/* 체크판과 말의 수 */

void initCheck(void) {
	for (int i = 0; i <= N; i++) {
		columnChk[i] = FALSE;
	}

	for (int i = 0; i <= 2 * N + 1; i++) {
		incDiagonalLineChk[i] = FALSE;
		decDiagonalLineChk[i] = FALSE;
	}

}

void nQueen(int row) {
	if (row > N) {
		placementCnt++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (columnChk[i] == FALSE && incDiagonalLineChk[row + i] == FALSE && decDiagonalLineChk[N + row - i] == FALSE) {
			columnChk[i] = TRUE;
			incDiagonalLineChk[row + i] = TRUE;
			decDiagonalLineChk[N + row - i] = TRUE;
			
			nQueen(row + 1);

			columnChk[i] = FALSE;
			incDiagonalLineChk[row + i] = FALSE;
			decDiagonalLineChk[N + row - i] = FALSE;
		}
	}
}
