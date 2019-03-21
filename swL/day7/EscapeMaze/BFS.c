#include <stdio.h>
#include "BFS.h"

int map[MAX + 1][MAX + 1]; 			/* 맵 배열 */
coord_t queue[MAX + 1];				/* 방문순서저장 큐 */
int N; 								/* 맵 행의 수 */
int M; 								/* 맵 열의 수 */
coord_t start; 						/* 출발 좌표 */
coord_t goal; 						/* 도착 좌표 */
int front;							/* 큐 출력 참조변수 */
int rear;							/* 큐 입력 참조변수 */
int dr[] = { 1, 0, -1, 0 };			/* 탐색대상 행의 상대 좌표 */
int dc[] = { 0, 1, 0, -1 };			/* 탐색대상 열의 상대좌표 */

void initMap(void) {
	int i;
	int j;

	for (i=1 ; i<=MAX ; i++) {
		for (j=1 ; j<=MAX ; j++) {
			map[i][j] = 0;
		}
	}
	N = MAX;
	M = MAX;
}

void createMap(void) {

	/*
	 * TO DO
	 */

	int input = 0;
	
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &input);

			if (input == '#') {
				map[i][j] = -2;
			} else if (input == '.') {
				map[i][j] = -1;
			} else if (input == 'S') {
				start.row = i;
				start.col = j;
			} else if (input == 'G') {
				map[i][j] = -1;
				goal.row = i;
				goal.col = j;
			}
		}
	}

}

void printMap(void) {
	int i;
	int j;

	printf("\n** 미로출력 **\n");
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {

			if ((i == start.row) && (j == start.col)) {		/* 출발점인 경우 */
				printf("%4c", 'S');
			}
			else if (map[i][j] == -1) {						/* 도로인 경우 */
				if ((i == goal.row) && (j == goal.col)) {	/* 도착점인 경우 */
					printf("%4c", 'G');
				}
				else {
					printf("%4c", '.');
				}
			}
			else if (map[i][j] == -2) {						/* 벽인 경우 */
				printf("%4c", '#');
			}
			else {											/* 그 이외의 경우 */
				printf("%4d", map[i][j]);
			}
		}
		printf("\n");
	}
}

int BFS(coord_t s, coord_t g) {

	/*
	 * TO DO
	 */
		coord_t tmp;

		queue[rear] = s;
		rear = (rear + 1) % MAX;;

		while (front != rear) {
			tmp = queue[front];
			front = (front + 1) % MAX;

			if (tmp.row == goal.row && tmp.col == goal.col) {
				break;
			}

			for (int i = 0; i < 4; i++) {
				coord_t new_pos;

				new_pos.row = tmp.row + dr[i];
				new_pos.col = tmp.col + dc[i];

				if (map[new_pos.row][new_pos.col] == -1) {
					queue[rear] = new_pos;
					rear = (rear + 1) % MAX;
					map[new_pos.row][new_pos.col] = map[tmp.row][tmp.col] + 1;
					
				}
			}
		}

	return map[goal.row][goal.col];
}
