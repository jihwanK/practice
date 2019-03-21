#include <stdio.h>
#include "MaxPath.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initMap();
	createMap();
	printMap();
	printf("[최대 값 : %d]\n", calc());
	printMap();
	printf("[각 위치에서의 dir 값] \n");
	printDir();
	printf("[전체 path 출력] \n");
	printPath();

	return 0;
}
