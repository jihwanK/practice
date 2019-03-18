/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node* next;
} node_t;

typedef struct _list {
  int cnt;
  node_t* head;
} list_t;

void init_list(list_t* p);
int add_first(list_t*p, int data);
void display_list(const list_t* p);
node_t* search_node(list_t* p, int data);
int remove_node(list_t* p, int data);
void sort_list(list_t* p);
void destroy_list(list_t* p);

int main(void) {
  list_t list;

  init_list(&list);

  display_list(&list);

  for (int i = 0; i < 4; i++) {
    add_first(&list, i+1);
  }

  display_list(&list);

  return 0;
}

void init_list(list_t* p) {
  p->cnt = 0;
  p->head = NULL;
}

int add_first(list_t* p, int data) {
  if (p == NULL) return -1;

  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  
  if (p->head == NULL) {
    p->head = new_node;
  } else {
    new_node->next = p->head;
    p->head = new_node;
  }

  p->cnt++;
  return 0;
}

void display_list(const list_t* p) {
  if (p == NULL) return;

  node_t* cur;
  cur = p->head;
  while(cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

node_t* search_node(list_t* p, int data) {
  if (p == NULL) return NULL;

  node_t* cur = p->head;

  while(cur != NULL) {
    if (cur->data == data) {
      break;
    }
  }

  return cur;
}

int remove_node(list_t* p, int data) {

}

void sort_list(list_t* p) {

}

void destroy_list(list_t* p) {

}
*/


/* with dummy node */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node* next;
} node_t;

typedef struct _list {
  int cnt;
  node_t* head;
  node_t* tail;
} list_t;

void init_list(list_t* p);
int add_first(list_t*p, int data);
int add_last(list_t* p, int data);
void display_list(const list_t* p);
node_t* search_node(const list_t* p, int data);
node_t* remove_node(list_t* p, int data);
void sort_list(list_t* p);
void destroy_list(list_t* p);

int main(void) {
  list_t list;
  node_t* res;

  init_list(&list);

  // display_list(&list);

  for (int i = 0; i < 10; i++) {
    add_first(&list, i+1);
  }
  
  // for (int i = 0; i < 4; i++) {
  //   add_last(&list, i+1);
  // }

  display_list(&list);
  printf("\n");

  for (int i = 0; i < 12; i++) {
    res = search_node(&list, i+1);

    if (res != NULL)
      printf("found %d \n", res->data);
    else {
      printf("cannot find\n");
    }
  }
  

  remove_node(&list, 10);
  display_list(&list);
  printf("\n");

  sort_list(&list);
  display_list(&list);
  printf("\n");

  destroy_list(&list);

  return 0;
}

void init_list(list_t* p) {
  node_t* dummy_head = (node_t*) malloc(sizeof(node_t));
  node_t* dummy_tail = (node_t*) malloc(sizeof(node_t));
  dummy_head->next = dummy_tail;
  dummy_tail->next = dummy_tail;
  p->head = dummy_head;
  p->tail = dummy_tail;
  p->cnt = 0;
}

int add_first(list_t* p, int data) {
  if (p == NULL) return -1;

  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->data = data;

  new_node->next = p->head->next;
  p->head->next = new_node;

  p->cnt++;

  return 0;
}

int add_last(list_t* p, int data) {
  if (p == NULL) return -1;

  node_t* cur = p->head;
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  
  if (new_node == NULL) return -1;

  new_node->data = data;

  while (cur->next != p->tail) {
    cur = cur->next;
  }

  new_node->next = p->tail;
  cur->next = new_node;
  
  p->cnt++;

  return 0;
}

void display_list(const list_t* p) {
  if (p == NULL) return;

  node_t* cur = p->head->next;

  while (cur != p->tail) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

node_t* search_node(const list_t* p, int data) {
  if (p == NULL) return NULL;

  node_t* cur = p->head->next;

  while (cur != p->tail) {
    if (cur->data == data) {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}

node_t* remove_node(list_t* p, int data) {
  if (p == NULL) return NULL;

  node_t* cur = p->head;

  while(cur->next != p->tail) {
    if (cur->next->data == data) {
      cur->next = cur->next->next;
      p->cnt--;
      return cur->next;
    }
    cur = cur->next;
  }
  return NULL;
}

void sort_list(list_t* p) {
  if (p == NULL) return;

  node_t* min = p->head->next;
  node_t* cur = min->next;

  while (min->next != p->tail) {
    while (cur != p->tail) {
      if (min->data > cur->data) {
        int tmp = min->data;
        min->data = cur->data;
        cur->data = tmp;
      }
      cur = cur->next;
    }
    min = min->next;
    cur = min->next;
  }
}

void destroy_list(list_t* p) {
  node_t* cur = p->head->next;
  node_t* tmp = cur;

  while (cur != p->tail) {
    cur = cur->next;
    free(tmp);
    tmp = cur;
  }

  free(p->head);
  free(p->tail);
}