#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Q q;
Q* qp = &q;

int create_Q (int size) {
  qp->queue = (char*) malloc(sizeof(char) * size);
  qp->size = size;
  qp->front = 0;
  qp->rear = 0;
}

int is_Q_empty() {
  return (qp->front == qp->rear);
}

int is_Q_full() {
  return (((qp->rear + 1) % qp->size) == qp->front);
}

int enqueue(char data) {
  if (qp == NULL) return -1;
  if (is_Q_full(qp) == 1) return -1;

  qp->queue[qp->rear] = data;
  qp->rear = ((qp->rear + 1) % qp->size);

  return 0;
}

int dequeue(char* data) {
  if (qp == NULL) return -1;
  if (is_Q_empty(qp) == 1) return -1;

  *data = qp->queue[qp->front];
  qp->front = ((qp->front + 1) % qp->size);

  return 0;
}

void printQ() {
  for (int i = qp->front; i != qp->rear; i = ((i + 1) % qp->size)) {
    printf("%3d", qp->queue[i]);
  }
  printf(" \n");
}

void destroyQ() {
  if (qp == NULL) return;

  free(qp->queue);
  qp->queue = NULL;
  qp->front = 0;
  qp->rear = 0;
  qp->size = 0;

  return;
}







// int main(void) {
//   char data;
  
//   create_Q(10);

//   for (int i = 1; i <= 13; i++)
//     enqueue(i);
//   printQ();

//   dequeue(&data);
//   printQ();
//   dequeue(&data);
//   dequeue(&data);
//   printQ();

//   enqueue(11);
//   enqueue(12);
//   enqueue(13);
//   enqueue(14);
//   printQ();

//   dequeue(&data);
//   printQ();
//   enqueue(14);
//   printQ();

//   destroyQ();

//   return 0;
// }
