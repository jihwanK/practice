#ifndef BOGGLE_H_
#define BOGGLE_H_

#define MAX 100
extern char board[][MAX + 1];		/* ��������迭 */
extern int N;						/* ������ ���� �� */
extern int M;						/* ������ ���� �� */
extern int dr[];					/* �˻� �� �����ǥ */
extern int dc[];					/* �˻� �� �����ǥ */
extern char word[MAX];				/* �˻��ܾ� */

void initBoard(void);
void createBoard(void);
void printBoard(void);
int searchWord(void);
int DFS(int row, int col, const char *word);

#endif /* BOGGLE_H_ */
