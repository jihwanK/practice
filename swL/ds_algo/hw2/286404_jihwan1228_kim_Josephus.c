#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
  int* queue;
  int size;
  int cur;
  int M;
} Q;

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

int init_joseqphus(Q* qp, int N, int M) {
  create_Q(qp, N, M);

  for (int i = 1; i <= qp->size; i++) {
    enqueue(qp, i);
  }

  qp->cur = -1;
}

int get_joseqphus(Q* qp) {
  int ret = 0;
  int M = qp->M;

  while(1) {
    qp->cur = ((qp->cur + 1) % qp->size);
    
    if (qp->queue[qp->cur] != -1) M--;

    if (M == 0) {
      ret =  qp->queue[qp->cur];
      qp->queue[qp->cur] = -1;
      break;
    }
  }
  return ret;
}


void print_josephus(Q* qp) {
  printf(" (%d, %d) 요세푸스 순열: ");
  // printf(" (%d, %d) josephus: ", qp->size, qp->M);

  for (int i = 0; i < qp->size; i++) {
    printf("%d ", get_joseqphus(qp));
  }
}

int main(void) {
  Q q;

  int N, M;

  printf("# N(인원수)와 M(간격수)를 입력하시오 (M<=N) : ");
  scanf("%d %d", &N, &M);

  init_joseqphus(&q, N, M);

  print_josephus(&q);

  return 0;
}