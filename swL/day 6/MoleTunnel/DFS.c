#include <stdio.h>
#include "DFS.h"

int bit[MAX + 1][MAX + 1] = {{0}, {0}};	/* �� 2���� �迭�ν� 0��°�� ������� ���� */
int bitInfo[MAX + 1] = { 0 };			/* �� ũ�� ���� �迭 */
int bitSize; 							/* ���� ���ο� ������ ũ�� */
int tunnelNumber; 						/* ���� Ž������ �� ��ȣ */
int dr[] = { 1, 0, -1, 0 };				/* �̵����� ���� �����ǥ */
int dc[] = { 0, 1, 0, -1 };				/* �̵����� ���� �����ǥ */

/* ���� �ʱ�ȭ �ϴ� �Լ� */
void initBit(void) {
	int i;
	int j;

	for (i=1 ; i<=MAX ; i++) {
		for (j=1 ; j<=MAX ; j++) {
			bit[i][j] = 0;
		}
	}
	bitSize = MAX;
}

/* ���Ϸκ��� �����͸� �о�鿩 ���� �����ϴ� �Լ� */
void createBit(void) {

	/*
	 * TO DO
	 */

}

/* �� ��� �Լ� */
void printBit(void) {
	int i;
	int j;

	for (i=1 ; i<=bitSize ; i++) {
		for (j=1 ; j<=bitSize ; j++) {
			printf("%2d", bit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


/* ���̿켱Ž�� �Լ��ν� ���� ��ǥ�� Ž����ȣ�� �μ��Ѵ�. */
void dfs(int row, int col, int tNum) {

	/*
	 * TO DO
	 */

}

/* �� Ž�� ������ ����ϴ� �Լ��ν� �� ��ȣ�� ���� ũ�⸦ ����Ѵ�. */
void output(void) {
	int i;

	/* �ͳ��� ũ�Ⱑ 0 �̻��� �˻� */
	for (i=1 ; i<=bitSize ; i++) {
		if (bitInfo[i] > 0) {
			printf("%d�� �δ������� ũ�� : %d\n", i, bitInfo[i]);
		}
	}
}

/* DFS Ž�� ���� �Լ� */
void startDFS(void) {

	/*
	 * TO DO
	 */

}
