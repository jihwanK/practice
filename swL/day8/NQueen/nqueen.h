#ifndef NQUEEN_H_
#define NQUEEN_H_
#define MAX_CNT 10

typedef enum _check { FALSE, TRUE } check_t;

extern check_t columnChk[];				/* �÷� üũ �迭 */
extern check_t incDiagonalLineChk[];	/* �밢�� üũ */
extern check_t decDiagonalLineChk[];	/* �밢�� üũ */
extern int placementCnt;				/* ��ġ ���� �� ī���� */
extern int N;							/* üũ�ǰ� ���� �� */

void initCheck(void);
void nQueen(int row);

#endif /* NQUEEN_H_ */
