#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
  int* stack;
  int top;
  int size;
} Stack;

void init_stack(Stack* sp, int size) {
  if (sp == NULL || size < 0)  {
    return;
  }
  sp->size = size;
  sp->stack = (int*) malloc(sizeof(int) * sp->size);
  if (sp->stack == NULL) {
    return;
  } 

  sp->top = 0;
}

int is_stack_full(Stack* sp) {
  return (sp->top == sp->size);
}

int is_stack_empty(Stack* sp) {
  return (sp->top == 0);
}

int push(Stack* sp, int data) {
  if (sp == NULL) return -1;
  if (is_stack_full(sp) == 1) return -1;
  
  sp->stack[sp->top] = data;
  sp->top++;

  return 0;
}

int pop(Stack* sp, int* data) {
  if (sp == NULL) return -1;
  if (is_stack_empty(sp) == 1) return -1;

  *data = sp->stack[sp->top-1];
  // sp->stack[sp->top-1] = -1;
  sp->top--;

  return *data;
}

int destroy_stack(Stack* sp) {
  free(sp->stack);

  return 0;
}


int main(void) {
  Stack s;
  int pop_data = 0;

  init_stack(&s, 10);

  push(&s, 10);
  push(&s, 11);
  push(&s, 12);
  push(&s, 13);


  pop(&s, &pop_data);
  printf("%d ", pop_data);
  pop(&s, &pop_data);
  printf("%d ", pop_data);
  pop(&s, &pop_data);
  printf("%d ", pop_data);
  pop(&s, &pop_data);
  printf("%d ", pop_data);


  destroy_stack(&s);

  return 0;
}