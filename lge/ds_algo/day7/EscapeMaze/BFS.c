#include <stdio.h>
#include "BFS.h"

int map[MAX + 1][MAX + 1]; 			/* �� �迭 */
coord_t queue[MAX + 1];				/* �湮�������� ť */
int N; 								/* �� ���� �� */
int M; 								/* �� ���� �� */
coord_t start; 						/* ��� ��ǥ */
coord_t goal; 						/* ���� ��ǥ */
int front;							/* ť ��� �������� */
int rear;							/* ť �Է� �������� */
int dr[] = { 1, 0, -1, 0 };			/* Ž����� ���� ��� ��ǥ */
int dc[] = { 0, 1, 0, -1 };			/* Ž����� ���� �����ǥ */

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

	printf("\n** �̷���� **\n");
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {

			if ((i == start.row) && (j == start.col)) {		/* ������� ��� */
				printf("%4c", 'S');
			}
			else if (map[i][j] == -1) {						/* ������ ��� */
				if ((i == goal.row) && (j == goal.col)) {	/* �������� ��� */
					printf("%4c", 'G');
				}
				else {
					printf("%4c", '.');
				}
			}
			else if (map[i][j] == -2) {						/* ���� ��� */
				printf("%4c", '#');
			}
			else {											/* �� �̿��� ��� */
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
