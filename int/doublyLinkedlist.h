#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <stdlib.h>
#include "word.h"
typedef enum {FALSE, TRUE} BOOL;

typedef struct _node Node;
struct _node
{
    /* data */
    Node* prev;
    Word data;
    Node* next;
};

typedef struct _list {
    Node* head;
    Node* tail;
    int size;
}List;

BOOL createList(List* lp);
BOOL addFirst(List* lp, Word data);
BOOL addLast(List* lp, Word data);
void displayList(List* lp);
BOOL removeNode(List* lp, Word data);
Node* searchNode(List* lp, Word data);
void destroyList(List* lp);


#endif