#ifndef _HEAP_H_
#define _HEAP_H_

#include "maze.h"
//#include "node.h"

/* variables */
extern int HEAP[MAX_SIZE];


/* functions */
int swap(int i, int j);
int down_heap(int i, int N) ;

#endif