#include <stdio.h>
#include <string.h>
#include "boggle.h"

char board[MAX][MAX + 1];
int N;
int M;
int dr[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dc[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
char word[MAX];

void initBoard(void) {

	/* TO DO */
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j <= MAX; j++) {
			board[i][j] = 0;
		}
	}
}

void createBoard(void) {

	/* TO DO */
	scanf("%d %d", &N, &M);
	scanf("%s", word);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
}

void printBoard(void) {

	/* TO DO */

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}

int searchWord(void) {

	/* TO DO */

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (DFS(i, j, word) == 0) {
				return 1;
			}
		}
	}
	
	return 0;
}

int DFS(int row, int col, const char *word) {

	/* TO DO */
	for (int i = 0; i < 8; i++) {
		int new_row = row + dr[i];
		int new_col = col + dc[i];

		if (new_col >= M || new_col < 0 || new_row >= N || new_row < 0) {
			continue;
		} else if (word[0] == '\0') {
			return 0;
		} else if (board[new_row][new_col] == word[0]) {
			return DFS(new_row, new_col, word + 1);
		}
		
	}
	return -1;
}
