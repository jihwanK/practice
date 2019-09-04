#include <stdio.h>
#include "DFS.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initBit();		/* 맵 초기화 */
	createBit();	/* 맵 생성 */
	printBit();		/* 맵 출력 */
	startDFS();		/* 탐색 시작 */
	printBit();		/* 맵 출력 */
	output();		/* 굴 정보 출력 */
}
