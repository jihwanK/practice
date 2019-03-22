#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100     // 맵의 가로 세로 최대 크기
#define ROAD -1     // 도로 표시 값
#define WALL -2     // 벽 표시 값

// int all_cases[500];


typedef struct {    // 좌표 구조체
	int row;
	int col;
} coord_t;

struct {            // 상대좌표 연산용 구조체 변수
	int row[4];
	int col[4];
	int dir;
} rc = {{-1, 0, 1, 0}, {0, -1, 0, 1}, 4 };

int gMap[MAX][MAX]; // 맵 배열
int gRow;           // 맵의 세로 크기
int gCol;           // 맵의 가로 크기
coord_t gStart;     // 출발 점
coord_t gGoal;      // 도착 점
int minV;           // 출발점에서 도착점까지의 최소거리 저장 변수
int maxV;           // 출발점에서 도착점까지의 최대거리 저장 변수
int rootCnt;        // 출발점에서 도착점까지의 경로의 수 저장 변수

// 맵 초기화 함수
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

// 맵 생성 함수
void create(void) {
	int i;
	int j;
	char ch;

	scanf("%d %d", &gRow, &gCol);
	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			scanf(" %c", &ch);
			switch(ch) {
			case 'S':               // 출발점인 경우
				gMap[i][j] = ROAD;
				gStart.row = i;
				gStart.col = j;
				break;
			case 'G':               // 도착점인 경우
				gGoal.row = i;
				gGoal.col = j;
				gMap[i][j] = ROAD;
				break;
			case '.':               // 도로인 경우
				gMap[i][j] = ROAD;
				break;
			default:                // 그 외의 경우
				gMap[i][j] = WALL;
				break;
			}
		}
	}
}

// 깊이 우선 탐색 (DFS) 함수
// 첫 번째 인수 : 탐색 좌표
// 두 번째 인수 : 탐색 이동 횟수
void dfs(coord_t s, int c) {

	if (s.row < 1 || s.col < 1 || s.row > gRow || s.col > gCol) {
		return;
	} else if (s.row == gGoal.row && s.col == gGoal.col) {
		if (c < minV) {
			minV = c;
		} else if (c > maxV) {
			maxV = c;
		}
		// all_cases[rootCnt] = c;
		rootCnt++;
		return;
	} else {
		for (int i = 0; i < rc.dir; i++) {
			int new_row = s.row + rc.row[i];
			int new_col = s.col + rc.col[i];

			if (gMap[new_row][new_col] == ROAD) {
				coord_t tmp = {new_row, new_col};
				gMap[new_row][new_col] = c;
				dfs(tmp, ++c);
				gMap[new_row][new_col] = ROAD;
				c--;
			}
		}
	}
	
}

// 맵 출력 함수
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
				break;
			}
		}
		printf("\n");
	}

	// for (int i = 0 ; i < 500; i++) {
	// 	printf("(%2d) %d \n", i, all_cases[i]);
	// }
}

int main(void) {
	int st, ed;

	freopen("data.txt", "r", stdin);    // 파일 입력 설정
	create();                           // 맵 생성

	minV = 10000;                       // 최소 경로값 저장 변수 초기화
	maxV = 0;                           // 최대 경로값 저장 변수 초기화
	rootCnt = 0;                        // 이동 경로 수 변수 초기화

	st = clock();                       // 탐색 시작 시간
	dfs(gStart, 0);                     // DFS 탐색 실행
	ed = clock();                       // 탐색 종료 시간

	print();                            // 맵 및 탐색 정보 출력
	printf("최소경로 : %d\n", minV);
	printf("최대경로 : %d\n", maxV);
	printf("경로수 : %d\n", rootCnt);
	printf("탐색시간 : %.6lf초\n", ((double)ed - st) / CLOCKS_PER_SEC);
	
	init();                             // 사용변수 초기화

	return 0;
}
