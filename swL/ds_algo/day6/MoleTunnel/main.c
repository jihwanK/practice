#include <stdio.h>
#include "DFS.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initBit();		/* �� �ʱ�ȭ */
	createBit();	/* �� ���� */
	printBit();		/* �� ��� */
	startDFS();		/* Ž�� ���� */
	printBit();		/* �� ��� */
	output();		/* �� ���� ��� */
}
