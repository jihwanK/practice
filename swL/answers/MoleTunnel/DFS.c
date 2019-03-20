#include <stdio.h>
#include "DFS.h"

int bit[MAX + 1][MAX + 1] = {{0}, {0}};	/* 맵 2차원 배열로써 0번째는 사용하지 않음 */
int bitInfo[MAX + 1] = { 0 };			/* 굴 크기 저장 배열 */
int bitSize; 							/* 맵의 가로와 세로의 크기 */
int tunnelNumber; 						/* 현재 탐색중인 굴 번호 */
int dr[] = { 1, 0, -1, 0 };				/* 이동가능 행의 상대좌표 */
int dc[] = { 0, 1, 0, -1 };				/* 이동가능 열의 상대좌표 */

/* 맵을 초기화 하는 함수 */
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

/* 파일로부터 데이터를 읽어들여 맵을 생성하는 함수 */
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

/* 맵 출력 함수 */
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

/* 깊이우선탐색 함수로써 맵의 좌표와 탐색번호를 인수한다. */
void dfs(int row, int col, int tNum) {
	int i;
	int nr;
	int nc;

	/* 해당 좌표가 굴이 아니면 종료 */
	if (bit[row][col] != 1) {
		return;
	}
	else {
		/* 굴 번호 표시 */
		bit[row][col] = tNum;
		/* 굴의 크기 증가 */
		bitInfo[tNum]++;

		/* 상하좌우 좌표에 대하여 */
		for (i=0 ; i<4 ; i++) {
			nr = row + dr[i];
			nc = col + dc[i];
			/* 유효한 범위이며 */
			if ((nr >= 1) && (nr <= bitSize) && (nc >= 1) && (nc <= bitSize)) {
				/* 미 탐색 구간이라면 */
				if (bit[nr][nc] == 1) {
					dfs(nr, nc, tNum);
				}
			}
		}
	}
}

/* 굴 탐색 정보를 출력하는 함수로써 굴 번호의 굴의 크기를 출력한다. */
void output(void) {
	int i;

	/* 터널의 크기가 0 이상을 검색 */
	for (i=1 ; i<=bitSize ; i++) {
		if (bitInfo[i] > 0) {
			printf("%d번 두더지굴의 크기 : %d\n", i, bitInfo[i]);
		}
	}
}

/* DFS 탐색 유도 함수 */
void startDFS(void) {
	int i;
	int j;

	/* 터널 시작번호 초기화 */
	tunnelNumber = 2;

	/* 터널 크기 정보 초기화 */
	for (i=1 ; i<=bitSize ; i++) {
		bitInfo[i] = 0;
	}

	/* 미 탐색 터널 검색 및 탐색 시작 호출 */
	for (i=1 ; i<=bitSize ; i++) {
		for (j=1 ; j<=bitSize ; j++) {
			if (bit[i][j] == 1) {
				dfs(i, j, tunnelNumber);
				++tunnelNumber;
			}
		}
	}
}
