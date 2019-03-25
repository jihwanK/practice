#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100         	// 맵의 최대 가로 세로 크기
#define ROAD -1         	// 도로 표시 값
#define WALL -2        		// 벽 표시 값

typedef struct {        	// 좌표 구조체
	int row;
	int col;
} coord_t;

struct {                	// 상대좌표 연산용 구조체 변수
	int row[4];
	int col[4];
	int dir;
} rc = {{-1, 0, 1, 0}, {0, -1, 0, 1}, 4 };

int gMap[MAX][MAX];     	// 맵 2차원 배열
int gRow;               	// 맵의 세로 크기
int gCol;               	// 맵의 가로 크기
coord_t gStart;         	// 출발점 좌표
coord_t gGoal;          	// 도착점 좌표

coord_t queue[MAX * MAX];   // BFS 탐색용 Queue
int front;                  // Queue 출력 참조 변수
int rear;                   // Queue 입력 참조 변수

/* 맵 초기화 함수로써 프로그램 실행 완료 후 호출한다 */
void init(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			gMap[i][j] = -1;
		}
	}
	gRow = 0;
	gCol = 0;
}

/* 맵 생성 함수 */
void create(void) {
	int i;
	int j;
	char ch;

	scanf("%d %d", &gRow, &gCol);
	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			scanf(" %c", &ch);
			switch(ch) {
			case 'S':                   // 출발점인 경우
				gMap[i][j] = ROAD;
				gStart.row = i;
				gStart.col = j;
				break;
			case 'G':                   // 도착점인 경우
				gGoal.row = i;
				gGoal.col = j;
				gMap[i][j] = ROAD;
				break;
			case '.':                   // 도로인 경우
				gMap[i][j] = ROAD;
				break;
			default:                    // 그 외의 경우
				gMap[i][j] = WALL;
				break;
			}
		}
	}
}

/* 너비우선탐색 (BFS) 함수로써 탐색 출발점을 인수로 한다. */
void bfs(coord_t s) {
	coord_t u, v;
	int i;

	front = 0; 						// 큐 초기화
	rear = 0;
	
	queue[rear++] = s;				// 큐에 출발점 enQueue
	gMap[s.row][s.col] = 0;			// 출발점에 대하여 방문체크

	while (front != rear) {         // 큐에 데이터가 비워질때까지 반복수행
		u = queue[front++];         // 큐로부터 정점(u)을 deQueue
		
		// 정점 u가 도착점이라면 탐색을 종료한다.
		if ((u.row == gGoal.row) && (u.col == gGoal.col)) {
			break;
		}

		// 점점 u에 인접한 정점 v에 대하여
		for (i=0 ; i<rc.dir ; i++) {
			v.row = u.row + rc.row[i];
			v.col = u.col + rc.col[i];

			if ((v.row >= 1) && (v.row <= gRow) && (v.col >= 1) && (v.col <= gCol)) {
				
				if (gMap[v.row][v.col] == ROAD) {					// 방문이 안된 정점이라면
					queue[rear++] = v;                  			// 큐에 정점(v)를 enQueue 한 후
					gMap[v.row][v.col] = gMap[u.row][u.col] + 1;    // 방문 체크 처리를 한다.
				}
			}
		}
	}
}

/* 맵 출력 함수 */
void print(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			switch (gMap[i][j]) {
			case ROAD:
				if ((gStart.row == i) && (gStart.col == j)) {
					printf("S");
				}
				else if ((gGoal.row == i) && (gGoal.col == j)) {
					printf("G");
				}
				else {
					printf(".");
				}
				break;
			case WALL:
				printf("%c", '#');
				break;
			default:
				printf("%c", 'O');
				break;
			}
		}
		printf("\n");
	}
}

int main(void) {
	int st, ed;

	freopen("data.txt", "r", stdin);        // 데이터 파일 개방

	create();                               // 맵 생성
	st = clock();                           // 탐색 전 시간 저장
	bfs(gStart);                            // 탐색 실행
	ed = clock();                           // 탐색 후 시간 저장

	print();                                // 탐색 후 맵 출력
	
	// 탐색 정보 출력
	printf("최단경로 : %d\n", gMap[gGoal.row][gGoal.col]);
	printf("탐색시간 : %.6lf초\n", ((double)ed - st) / CLOCKS_PER_SEC);

	// 사용 배열 및 변수 초기화
	init();

	return 0;
}
