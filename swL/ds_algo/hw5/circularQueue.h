#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_
#include<stdbool.h>

typedef struct _queue { /* ����ť ���� ����ü */
	int *queue;
	int size;
	int front, rear;
}Queue;

bool createQueue(Queue * qp, int size);		/* ť ���� �� �ʱ�ȭ �Լ� */
bool isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
bool isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
bool enqueue(Queue * qp, int enqueData);		/* ť�� ������ �ϳ��� ���� �� */
bool dequeue(Queue * qp, int * dequeData);	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp);			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp);				/* ť �Ҹ� �Լ� */
#endif /* CIRCULARQUEUE_H_ */
