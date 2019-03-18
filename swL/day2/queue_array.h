#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct _queue {
  int* queue;
  int size;
  int front;
  int rear;
} Q;

int create_Q (Q* qp, int size);
int is_Q_empty(const Q* qp);
int is_Q_full(const Q* qp);
int enqueue(Q* qp, int data);
int dequeue(Q* qp, int* data);
void printQ(const Q* qp);
void destroyQ(Q* qp);

#endif