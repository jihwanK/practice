#include <stdio.h>
#include "Floyd.h"

int d[MAX + 1][MAX + 1];
int p[MAX + 1][MAX + 1];
int vertex;
int edge;

void initGraph(void) {
	/*
	 * ��� ������ ���Ͽ� ������ ������ ����ġ��
	 * �������� ���� ������ INF
	 * ������� �������� ������ ��� 0���� �ʱ�ȭ �Ѵ�.
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
				printf("%4s", "��");
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

	/* �߰����� ������ �ϳ��� �÷����� i ������ j �������� �ִ� ��θ� ���Ѵ�. */
	for (k=1 ; k<=vertex ; k++) {					/* ��ó���� ��� */
		for (i=1 ; i<=vertex ; i++) {				/* ��� ��� */
			for (j=1 ; j<=vertex ; j++) {			/* ���� ��� */
				if ((d[i][k] + d[k][j]) < d[i][j]) {	/* i -> k - j ��ΰ� i -> j ����� ����ġ���� �۴ٸ� */
					d[i][j] = d[i][k] + d[k][j];		/* i -> j ����� ����ġ�� i -> k -> j�� ����ġ�� ���� */
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

	for (i=1 ; i<=vertex ; i++) {					/* �� �������� �� ���������� ����� ����Ѵ�. */
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
