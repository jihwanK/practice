#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
  int* queue;
  int size;
  int front;
  int rear;
} Q;

int create_Q (Q* qp, int size) {
  qp->queue = (int*) malloc(sizeof(int) * size);
  qp->size = size;
  qp->front = 0;
  qp->rear = 0;
}

int is_Q_empty(const Q* qp) {
  return (qp->front == qp->rear);
}

int is_Q_full(const Q* qp) {
  return (((qp->rear + 1) % qp->size) == qp->front);
}

int enqueue(Q* qp, int data) {
  if (qp == NULL) return -1;
  if (is_Q_full(qp) == 1) return -1;

  qp->queue[qp->rear] = data;
  qp->rear = ((qp->rear + 1) % qp->size);

  return 0;
}

int dequeue(Q* qp, int* data) {
  if (qp == NULL) return -1;
  if (is_Q_empty(qp) == 1) return -1;

  *data = qp->queue[qp->front];
  qp->front = ((qp->front + 1) % qp->size);

  return 0;
}

void printQ(const Q* qp) {
  for (int i = qp->front; i != qp->rear; i = ((i + 1) % qp->size)) {
    printf("%3d", qp->queue[i]);
  }
  printf(" \n");
}

void destroyQ(Q* qp) {
  if (qp == NULL) return;

  free(qp->queue);
  qp->queue = NULL;
  qp->front = 0;
  qp->rear = 0;
  qp->size = 0;

  return;
}

int main(void) {
  Q q;
  int data;
  
  create_Q(&q, 10);

  for (int i = 1; i <= 13; i++)
    enqueue(&q, i);
  printQ(&q);

  dequeue(&q, &data);
  printQ(&q);
  dequeue(&q, &data);
  dequeue(&q, &data);
  printQ(&q);

  enqueue(&q, 11);
  enqueue(&q, 12);
  enqueue(&q, 13);
  enqueue(&q, 14);
  printQ(&q);

  dequeue(&q, &data);
  printQ(&q);
  enqueue(&q, 14);
  printQ(&q);

  destroyQ(&q);

  return 0;
}