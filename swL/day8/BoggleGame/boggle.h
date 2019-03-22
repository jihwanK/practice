#ifndef BOGGLE_H_
#define BOGGLE_H_

#define MAX 100
extern char board[][MAX + 1];		/* 문자저장배열 */
extern int N;						/* 보드판 행의 수 */
extern int M;						/* 보드판 열의 수 */
extern int dr[];					/* 검색 행 상대좌표 */
extern int dc[];					/* 검색 열 상대좌표 */
extern char word[MAX];				/* 검색단어 */

void initBoard(void);
void createBoard(void);
void printBoard(void);
int searchWord(void);
int DFS(int row, int col, const char *word);

#endif /* BOGGLE_H_ */
