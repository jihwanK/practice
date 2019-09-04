#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct _queue {
  char* queue;
  int size;
  int front;
  int rear;
} Q;

extern Q q;
extern Q* qp;

int create_Q (int size);
int is_Q_empty();
int is_Q_full();
int enqueue(char data);
int dequeue(char* data);
void printQ();
void destroyQ();

#endif