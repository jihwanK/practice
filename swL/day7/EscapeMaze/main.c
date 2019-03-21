#include <stdio.h>
#include "BFS.h"

int main(void) {
	int dist;
	int testcase;

	freopen("data.txt", "r", stdin);

	initMap();
	createMap();

	dist = BFS(start, goal);
	if (dist > 0) {
		printf("최단거리 : %d\n", dist);
	}
	else {
		printf("도달할 수 없습니다.\n");
	}
	printMap();

	
	return 0;
}
