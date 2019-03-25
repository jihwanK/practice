#include <stdio.h>
#include "Floyd.h"

int d[MAX + 1][MAX + 1];
int p[MAX + 1][MAX + 1];
int vertex;
int edge;

void initGraph(void) {

	/*
	 * 모든 정점에 대하여 인접한 정점은 가중치로
	 * 인접하지 않은 정점은 INF
	 * 출발점과 도착점이 동일한 경우 0으로 초기화 한다.
	 */
	scanf("%d %d", &vertex, &edge);

	for (int i = 0; i < edge; i++) {
		int v1, v2, weight;
		scanf("%d %d %d", &v1, &v2, &weight);
		d[v1][v2] = weight;
	}
}

void createGraph(void) {

	/*
	 * TO DO
	 */
	
	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			p[i][j] = NIL;
			if ((d[i][j] == 0) && (i != j)) {
				d[i][j] = INF;
			} else if (i == j) {
				d[i][j] = 0;
				p[i][j] = 0;
			}
		}
	}

}

void printGraph(void) {
	int i;
	int j;

	for (i=0 ; i<=vertex ; i++) {
		if (i == 0) {
			printf("%3s", "");
		}
		else {
			printf("%3d", i);
		}
	}
	printf("\n");

	for (i=1 ; i<=vertex ; i++) {
		printf("%3d ", i);

		for (j=1 ; j<=vertex ; j++) {
			if (d[i][j] == INF) {
				printf("%4s", "∞");
			}
			else {
				printf("%3d", d[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void floydWarshall(void) {

	/*
	 * TO DO
	 */

}

void path(int s, int t) {

	/*
	 * TO DO
	 */

}

void printPath(int s, int t) {

	/*
	 * TO DO
	 */

}


void printDistance(void) {
	int i;
	int j;

	for (i=1 ; i<=vertex ; i++) {					/* 각 지점에서 각 지점까지의 비용을 출력한다. */
		for (j=1 ; j<=vertex ; j++) {
			printf("%d -> %d : %2d\n", i, j, d[i][j]);
		}
	}
}

void printPredecessor(void) {
	int i;
	int j;

	for (i=0 ; i<=vertex ; i++) {
		if (i == 0) {
			printf(" ");
		}
		else {
			printf("%3d", i);
		}
	}
	printf("\n");

	for (i=1 ; i<=vertex ; i++) {
		printf("%d ", i);

		for (j=1 ; j<=vertex ; j++) {
			printf("%3d", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
