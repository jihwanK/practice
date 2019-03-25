#include <stdio.h>
#include "MaxPath.h"

int map[MAX + 1][MAX + 1];
int dir[MAX + 1][MAX + 1];
int N;

void initMap(void) {

	/*
	 * TO DO
	 */
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
			dir[i][j] = 0;
		}
	}

}

void createMap(void) {

	/*
	 * TO DO
	 */
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

}

void printMap(void) {
	int i;
	int j;

	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printDir(void) {

	/*
	 * TO DO
	 */
	int i;
	int j;

	for (i=1 ; i<=N ; i++) {
		for (j=1 ; j<=N ; j++) {
			printf("%3c", dir[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int calc(void) {

	/*
	 * TO DO
	 */
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j-1] > map[i-1][j]) {
				map[i][j] = map[i][j] + map[i][j-1];
				dir[i][j] = 'w';
			} else {
				map[i][j] = map[i][j] + map[i-1][j];
				dir[i][j] = 'n';
			}
		}
	}

	return map[N][N];
}

void printPath(void) {

	/*
	 * TO DO
	 */
	int i = N, j = N;


	while (i != 1 || j != 1) {
		printf("dir[%d][%d] => ", i, j);
		if (dir[i][j] == 'w') {
			j = j - 1;
		} else if (dir[i][j] == 'n') {
			i = i - 1;
		}
	}
	printf("dir[%d][%d] \n", i, j);
}
