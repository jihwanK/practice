#include <stdio.h>
#include "DFS.h"

int main(void) {
	freopen("data.txt", "r", stdin);

	initBit();		/* ¸Ê ÃÊ±âÈ­ */
	createBit();	/* ¸Ê »ı¼º */
	printBit();		/* ¸Ê Ãâ·Â */
	startDFS();		/* Å½»ö ½ÃÀÛ */
	printBit();		/* ¸Ê Ãâ·Â */
	output();		/* ±¼ Á¤º¸ Ãâ·Â */

	return 0;
}
