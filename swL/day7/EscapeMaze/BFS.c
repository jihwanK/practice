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

}

void printMap(void) {
	int i;
	int j;

	printf("\n** �̷���� **\n");
	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=M ; j++) {

			if ((i == start.row) && (j == start.col)) {		/* ������� ��� */
				printf("%c", 'S');
			}
			else if (map[i][j] == -1) {						/* ������ ��� */
				if ((i == goal.row) && (j == goal.col)) {	/* �������� ��� */
					printf("%c", 'G');
				}
				else {
					printf("%c", '.');
				}
			}
			else if (map[i][j] == -2) {						/* ���� ��� */
				printf("%c", '#');
			}
			else {											/* �� �̿��� ��� */
				printf("%c", map[i][j] + '0');
			}
		}
		printf("\n");
	}
}

int BFS(coord_t s, coord_t g) {

	/*
	 * TO DO
	 */

	return 0;
}
