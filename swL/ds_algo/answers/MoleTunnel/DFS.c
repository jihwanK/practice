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
	int i;
	int j;

	scanf("%d", &bitSize);
	for (i=1 ; i<=bitSize ; i++) {
		for (j=1 ; j<=bitSize ; j++) {
			scanf("%d", &bit[i][j]);
		}
	}
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
	int i;
	int nr;
	int nc;

	/* �ش� ��ǥ�� ���� �ƴϸ� ���� */
	if (bit[row][col] != 1) {
		return;
	}
	else {
		/* �� ��ȣ ǥ�� */
		bit[row][col] = tNum;
		/* ���� ũ�� ���� */
		bitInfo[tNum]++;

		/* �����¿� ��ǥ�� ���Ͽ� */
		for (i=0 ; i<4 ; i++) {
			nr = row + dr[i];
			nc = col + dc[i];
			/* ��ȿ�� �����̸� */
			if ((nr >= 1) && (nr <= bitSize) && (nc >= 1) && (nc <= bitSize)) {
				/* �� Ž�� �����̶�� */
				if (bit[nr][nc] == 1) {
					dfs(nr, nc, tNum);
				}
			}
		}
	}
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
	int i;
	int j;

	/* �ͳ� ���۹�ȣ �ʱ�ȭ */
	tunnelNumber = 2;

	/* �ͳ� ũ�� ���� �ʱ�ȭ */
	for (i=1 ; i<=bitSize ; i++) {
		bitInfo[i] = 0;
	}

	/* �� Ž�� �ͳ� �˻� �� Ž�� ���� ȣ�� */
	for (i=1 ; i<=bitSize ; i++) {
		for (j=1 ; j<=bitSize ; j++) {
			if (bit[i][j] == 1) {
				dfs(i, j, tunnelNumber);
				++tunnelNumber;
			}
		}
	}
}
