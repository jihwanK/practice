#include <stdio.h>
#include "Floyd.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initGraph();
	createGraph();
	printGraph();
	floydWarshall();
	printGraph();
	printDistance();
	printPredecessor();
	printPath(1, 3);

	return 0;
}
