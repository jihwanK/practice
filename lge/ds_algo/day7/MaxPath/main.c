#include <stdio.h>
#include "MaxPath.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initMap();
	createMap();
	printMap();
	printf("[�ִ� �� : %d]\n", calc());
	printMap();
	printf("[�� ��ġ������ dir ��] \n");
	printDir();
	printf("[��ü path ���] \n");
	printPath();

	return 0;
}
