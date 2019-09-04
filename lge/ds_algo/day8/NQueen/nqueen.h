#ifndef NQUEEN_H_
#define NQUEEN_H_
#define MAX_CNT 10

typedef enum _check { FALSE, TRUE } check_t;

extern check_t columnChk[];				/* 컬럼 체크 배열 */
extern check_t incDiagonalLineChk[];	/* 대각선 체크 */
extern check_t decDiagonalLineChk[];	/* 대각선 체크 */
extern int placementCnt;				/* 배치 가능 수 카운터 */
extern int N;							/* 체크판과 말의 수 */

void initCheck(void);
void nQueen(int row);

#endif /* NQUEEN_H_ */
