#include <stdio.h>
#include "MaxPath.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initMap();
	createMap();
	printMap();
	printf("ÃÖ´ë °ª : %d\n", calc());
	printMap();
	//printDir();
	//printPath();

	return 0;
}
