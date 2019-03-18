#include <stdio.h>
#include "heap.h"

int main(void) {
  heap_t Heap;
  int del;

  craete_heap(&Heap, 10);

  insert_heap(&Heap, 10);
  insert_heap(&Heap, 3);
  insert_heap(&Heap, 5);
  insert_heap(&Heap, 7);

  delete_heap(&Heap, &del);

  print_heap(&Heap);

  return 0;
}