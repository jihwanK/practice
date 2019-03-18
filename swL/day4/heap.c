#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


bool_t craete_heap(heap_t* hp, int size) {
  hp->heap = (int*) malloc(sizeof(int) * size);
  hp->size = size;
  hp->count = 0;
}

bool_t is_heap_empty(heap_t* hp) {
  if (hp == NULL) return FALSE;

  if (hp->count == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

bool_t is_heap_full(heap_t* hp) {
  if (hp == NULL) return FALSE;

  if (hp->count == hp->size) {
    return TRUE;
  } else {
    return FALSE;
  }
}

bool_t insert_heap(heap_t* hp, int data) {
  if (hp == NULL) return FALSE;
  
  int idx = 1;

  if (hp->size == 0) {
    hp->heap[1] = data;
    return TRUE;
  }

  hp->heap[hp->size + 1] = data;
  up_heap(hp, hp->size + 1);
  hp->size++;

  return TRUE;
}

bool_t delete_heap(heap_t* hp, int* get_data) {

}

void up_heap(heap_t* hp, int child) {
  int parent = child / 2;
  
  while ((child != 1) && (hp->heap[child] < hp->heap[parent])) {
    hp->heap[parent] = hp->heap[child];
    parent = child / 2;
  }
}

void down_heap(heap_t* hp, int parent) {

}

void print_heap(const heap_t* hp) {

}

void destroy_heap(heap_t* hp) {

}
