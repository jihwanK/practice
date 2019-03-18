#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

int create_Q (Q* qp, int size, int M) {
  qp->queue = (int*) malloc(sizeof(int) * size);
  qp->size = size;
  qp->cur = 0;
  qp->M = M;
}

int enqueue(Q* qp, int data) {
  if (qp == NULL) return -1;

  qp->queue[qp->cur] = data;
  qp->cur = ((qp->cur + 1) % qp->size);

  return 0;
}

// int dequeue(Q* qp, int* data) {
//   if (qp == NULL) return -1;

//   *data = qp->queue[qp->cur];
//   qp->cur = ((qp->cur + 1) % qp->size);

//   return 0;
// }