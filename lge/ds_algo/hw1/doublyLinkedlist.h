#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include<stdlib.h>
#include "word.h"
typedef enum{ FALSE, TRUE }  BOOL;

typedef struct _node Node;	/* ����ü ��� ���������� */
struct  _node {				/* ��� ����ü (�ڱ����� ����ü ���) */
	Node *prev;				/* �� ��带 ����Ű�� ������ */
	Word data;
	Node *next;				/* �� ��带 ����Ű�� ������ */
};

typedef  struct  _list {	/* ���� ����Ʈ ���� ����ü */
	Node *head;				/* head pointer (head node ����Ŵ) */
	Node *tail; 			/* tail pointer (tail node ����Ŵ) */
	int size;				/* ���� ����Ʈ�� ũ�� - ���� data node�� ���� */
}List;

BOOL createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
BOOL addFirst(List *lp, Word data); /* head node �ڿ� node �߰�(���� ����) */
BOOL addLast(List *lp, Word data);  /* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp);		    /* ����Ʈ ���� ��� ������ ��� */
BOOL removeNode(List *lp, Word data); /* data ��� ���� */
Node * searchNode(List *lp, Word data);	/* data�� ��ġ�ϴ� node �˻� */
void destroyList(List *lp);	/* ����Ʈ ���� ��� ��带 ���� */

#endif /* DOUBLYLINKEDLIST_H_ */

