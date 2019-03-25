#include <stdio.h>
#include <string.h>
#include "doublyLinkedlist.h"

BOOL createList(List *lp);					
BOOL addFirst(List *lp, Word data);
BOOL addLast(List *lp, Word data);
void displayList(List *lp);	
BOOL removeNode(List *lp, Word data); 
Node * searchNode(List *lp, Word data);
void destroyList(List *lp);

BOOL createList(List *lp) {
  lp->head = (Node*) malloc(sizeof(Node));
  lp->tail = (Node*) malloc(sizeof(Node));

  lp->head->next = lp->tail;
  lp->head->prev = lp->head;
  lp->tail->next = lp->tail;
  lp->tail->prev = lp->head;

  lp->size = 0;
}

BOOL addFirst(List *lp, Word data) {
  if (lp == NULL) return -1;

  Node* new_node = (Node*) malloc(sizeof(Node));
  strcpy(new_node->data.word, data.word);
  new_node->data.len = data.len;

  new_node->next = lp->head->prev;
  lp->head->next = new_node;
  new_node->next->prev = new_node;
  new_node->prev = lp->head;

  lp->size++;
}

BOOL addLast(List *lp, Word data) {
  if (lp == NULL) return -1;

  Node* new_node = (Node*) malloc(sizeof(Node));
  strcpy(new_node->data.word, data.word);
  new_node->data.len = data.len;

  new_node->next = lp->tail;
  new_node->prev = lp->tail->prev;
  new_node->prev->next = new_node;
  lp->tail->prev = new_node;

  lp->size++;
}

void displayList(List *lp) {
  if (lp == NULL) return;

  Node* cur = lp->head->next;

  while (cur != lp->tail) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

BOOL removeNode(List *lp, Word data) {
  if (lp == NULL) return FALSE;

  Node* cur = lp->head;

  cur = searchNode(lp, data);
  if (cur != NULL) {
    cur->next = cur->next->next;
    cur->next->prev = cur;
    return TRUE;
  }

  return FALSE;
}

Node * searchNode(List *lp, Word data) {
  if (lp == NULL) return NULL;

  Node* cur = lp->head->next;

  while (cur != lp->tail) {
    if ((strcmp(cur->data.word, data.word) == 0) && (cur->data.len == data.len)) {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}

void destroyList(List *lp) {
  Node* cur = lp->head->next;
  Node* tmp = cur;

  while (cur != lp->tail) {
    cur = cur->next;
    free(tmp);
    tmp = cur;
  }

  free(lp->head);
  free(lp->tail);
}