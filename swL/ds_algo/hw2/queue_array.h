#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct _queue {
  int* queue;
  int size;
  int cur;
  int M;
} Q;

int create_Q (Q* qp, int size, int M);
int enqueue(Q* qp, int data);

#endif