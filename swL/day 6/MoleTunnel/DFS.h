#ifndef DFS_H_
#define MAX 30 							/* 맵의 최대 크기는 30 x 30 */

extern int bit[][MAX + 1]; 					/* 맵 2차원 배열로써 0번째는 사용하지 않음 */
extern int bitInfo[];					/* 굴 크기 저장 배열 */
extern int bitSize; 					/* 맵의 가로와 세로의 크기 */
extern int tunnelNumber; 				/* 현재 탐색중인 굴 번호 */
extern int dr[];						/* 이동가능 행 상대좌표 */
extern int dc[];						/* 이동가능 열 상대좌표 */

void initBit(void);
/* 파일로부터 데이터를 읽어들여 맵을 생성하는 함수 */
void createBit(void);
/* 맵 출력 함수 */
void printBit(void);
/* 깊이우선탐색 함수로써 맵의 좌표와 탐색번호를 인수한다. */
void dfs(int row, int col, int tNum);
/* 굴 탐색 정보를 출력하는 함수로써 굴 번호의 굴의 크기를 출력한다. */
void output(void);
/* dfs탐색 유도 함수 */
void startDFS(void);

#endif /* DFS_H_ */
