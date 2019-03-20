#ifndef DFS_H_
#define MAX 30 							/* ���� �ִ� ũ��� 30 x 30 */

extern int bit[][MAX + 1]; 					/* �� 2���� �迭�ν� 0��°�� ������� ���� */
extern int bitInfo[];					/* �� ũ�� ���� �迭 */
extern int bitSize; 					/* ���� ���ο� ������ ũ�� */
extern int tunnelNumber; 				/* ���� Ž������ �� ��ȣ */
extern int dr[];						/* �̵����� �� �����ǥ */
extern int dc[];						/* �̵����� �� �����ǥ */

void initBit(void);
/* ���Ϸκ��� �����͸� �о�鿩 ���� �����ϴ� �Լ� */
void createBit(void);
/* �� ��� �Լ� */
void printBit(void);
/* ���̿켱Ž�� �Լ��ν� ���� ��ǥ�� Ž����ȣ�� �μ��Ѵ�. */
void dfs(int row, int col, int tNum);
/* �� Ž�� ������ ����ϴ� �Լ��ν� �� ��ȣ�� ���� ũ�⸦ ����Ѵ�. */
void output(void);
/* dfsŽ�� ���� �Լ� */
void startDFS(void);

#endif /* DFS_H_ */
