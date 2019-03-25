#include <stdio.h>
#include "nqueen.h"

check_t columnChk[MAX_CNT + 1];					/* �÷� üũ �迭 */
check_t incDiagonalLineChk[(MAX_CNT * 2) + 1];	/* �밢�� üũ */
check_t decDiagonalLineChk[(MAX_CNT * 2) + 1];	/* �밢�� üũ */
int placementCnt;								/* ��ġ ���� �� ī���� */
int N;											/* üũ�ǰ� ���� �� */

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
