#ifndef BFS_H_
#define BFS_H_

#define MAX 100 				/* 미로맵의 최대 크기 */
typedef struct _coord { 		/* 행열 좌표를 저장하는 구조체 */
	int row;
	int col;
} coord_t;

extern int map[][MAX + 1]; 		/* 맵 배열 */
extern coord_t queue[];			/* 방문순서저장 큐 */
extern int N; 					/* 맵 행의 수 */
extern int M; 					/* 맵 열의 수 */
extern coord_t start; 			/* 출발 좌표 */
extern coord_t goal; 			/* 도착 좌표 */
extern int front;				/* 큐 출력 참조변수 */
extern int rear;				/* 큐 입력 참조변수 */
extern int dr[];				/* 탐색대상 행의 상대 좌표 */
extern int dc[];				/* 탐색대상 열의 상대좌표 */

void initMap(void);
void createMap(void);
void printMap(void);
int BFS(coord_t s, coord_t g);

#endif /* BFS_H_ */
