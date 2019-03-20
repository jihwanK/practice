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
	int i;
	int j;

	for (i=0 ; i<MAX ; i++) {
		for (j=0 ; j<MAX ; j++) {
			if (i == j) {
				d[i][j] = 0;
			}
			else {
				d[i][j] = INF;
			}
			p[i][j] = NIL;
		}
	}
}

void createGraph(void) {
	int x;
	int y;
	int w;
	int i;

	scanf("%d %d", &vertex, &edge);
	for (i=0 ; i<edge ; i++) {
		scanf("%d %d %d", &x, &y, &w);
		d[x][y] = w;
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
	int i;
	int j;
	int k;

	/* 중간정점 집합을 하나씩 늘려가며 i 정점과 j 정점간의 최단 경로를 구한다. */
	for (k=1 ; k<=vertex ; k++) {					/* 거처가는 노드 */
		for (i=1 ; i<=vertex ; i++) {				/* 출발 노드 */
			for (j=1 ; j<=vertex ; j++) {			/* 도착 노드 */
				if ((d[i][k] + d[k][j]) < d[i][j]) {	/* i -> k - j 경로가 i -> j 경로의 가중치보다 작다면 */
					d[i][j] = d[i][k] + d[k][j];		/* i -> j 경로의 가중치를 i -> k -> j의 가중치로 변경 */
					p[i][j] = k;
				}
			}
		}
	}
}

static void path(int s, int t) {
	if (p[s][t] == NIL) {
		return;
	}
	else {
		path(s, p[s][t]);
		printf("%d > ", p[s][t]);
		path(p[s][t], t);
	}
}

void printPath(int s, int t) {
	printf("%d > ", s);
	path(s, t);
	printf("%d\n", t);
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
