#include <stdio.h> 
#include <malloc.h> 
#include "circularQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� true, �����ϸ� false ����
--------------------------------------------------------------------------------------*/
bool createQueue(Queue * qp, int size)
{
	if (qp == NULL) {  /* qp ������ NULL check*/
		return false;
	}
	qp->queue = (int *)calloc(size, sizeof(int));	/* queue �޸� �Ҵ� */
	if (qp->queue != NULL) {	/* queue �޸� �Ҵ� ���� �� */
		qp->size = size;
		qp->front = 0;
		qp->rear = 0;
		return true;
	}
	else {	/* queue �޸� �Ҵ� ���� �� */
		return false;
	}	
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� true ����, ������� ������ false ����
--------------------------------------------------------------------------------------*/
bool isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return false;
	}

	if (qp->front == qp->rear)	/* queue�� �ֺ�� ������ */
		return true;
	else
		return false;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - ť�� �����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� ������ true ����, �ƴϸ� false ����
--------------------------------------------------------------------------------------*/
bool isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return false;
	}

	if (qp->front == (qp->rear + 1) % qp->size) /* queue�� ������ ��� ������ */
		return true;
	else
		return false;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
			  	  enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� true, �����ϸ� false ����
--------------------------------------------------------------------------------------*/
bool enqueue(Queue * qp, int enqueData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return false;
	}

	if (isQueueFull(qp))	/* queue�� ���������� enqueue �Ұ� */ 
	{
		return false;
	}

	/* rear ��ġ�� ������ ���� �� rear ���� */
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return true;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ true, �����ϸ� false ����
--------------------------------------------------------------------------------------*/
bool dequeue(Queue * qp, int * dequeData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return false;
	}

	if (isQueueEmpty(qp))	/* ť�� ��������� dequeue �Ұ� */
	{
		return false;
	}

	/* �����͸� front��ġ���� ���� dequeData�� ����Ű�� ���� ���� �� */
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;

	return true;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	/* queue���� ��� ������ ��� (dequeue �ϸ� ��µǴ� ������ ���) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("%d ", qp->queue[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}

	if (qp->queue != NULL) { /* queue�� ���Ǵ� �迭 �޸� ���� */
		free(qp->queue);
	}
	qp->queue = NULL;	/* queue ����� NULL pointer�� �ʱ�ȭ */
	qp->size = 0;		/* size����� 0���� �ʱ�ȭ */
	qp->front = qp->rear = 0;	/* front, rear ����� 0���� �ʱ�ȭ */
}
