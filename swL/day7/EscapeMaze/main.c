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
		printf("�ִܰŸ� : %d\n", dist);
	}
	else {
		printf("������ �� �����ϴ�.\n");
	}
	printMap();

	
	return 0;
}
