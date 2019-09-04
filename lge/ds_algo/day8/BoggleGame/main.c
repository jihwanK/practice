#include <stdio.h>
#include "boggle.h"

int main(void) {
	int T;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc=0 ; tc<T ; tc++) {
		initBoard();
		createBoard();
		printBoard();
		if (searchWord() == 1) {
			printf("+ Existence!!(%s)\n\n", word);
		}
		else {
			printf("+ Nonexistence!!(%s)\n\n", word);
		}
	}

	return 0;
}
