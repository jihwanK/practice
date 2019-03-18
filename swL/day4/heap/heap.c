#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "heap.h"


bool_t craete_heap(heap_t* hp, int size) {
  hp->heap = (int*) malloc(sizeof(int) * (size + 1));
  hp->heap[0] = 987654321;
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
  if (is_heap_full(hp) == TRUE) return FALSE;
  
  hp->count++;
  hp->heap[hp->count] = data;
  up_heap(hp, hp->count);

  return TRUE;
}

bool_t delete_heap(heap_t* hp, int* get_data) {
  if (hp == NULL) return FALSE;
  if (is_heap_empty(hp) == TRUE) return FALSE;

  *get_data = hp->heap[1];
  
  if (hp->count != 1) {
    hp->heap[1] = hp->heap[hp->count];
    hp->count--;
    down_heap(hp, 1);
  }
}

void up_heap(heap_t* hp, int child) {
  if (hp == NULL) return;

  int parent = child / 2;
  
  while ((child > 1) && (hp->heap[child] < hp->heap[parent])) {
    int tmp = hp->heap[parent];
    hp->heap[parent] = hp->heap[child];
    hp->heap[child] = tmp;
    parent = child / 2;
  }
}

void down_heap(heap_t* hp, int parent) {
  if (hp == NULL) return;

  while (parent < hp->count) {
    int l_child = 2 * parent;
    int r_child = 2 * parent + 1;

    if (r_child <= hp->count) {
      if (hp->heap[l_child] > hp->heap[r_child]) {
        if (hp->heap[parent] < hp->heap[r_child]) break;

        int tmp = hp->heap[parent];
        hp->heap[parent] = hp->heap[r_child];
        hp->heap[r_child] = tmp;
        parent = r_child;
      } else {
        if (hp->heap[parent] < hp->heap[l_child]) break;

        int tmp = hp->heap[parent];
        hp->heap[parent] = hp->heap[l_child];
        hp->heap[l_child] = tmp;
        parent = l_child;
      }
    } else if (l_child <= hp->count) {
      if (hp->heap[parent] < hp->heap[l_child]) break;

      int tmp = hp->heap[parent];
      hp->heap[parent] = hp->heap[l_child];
      hp->heap[l_child] = tmp;
      parent = l_child;
    }
  }

}

void print_heap(const heap_t* hp) {
  int tab;

  for (int i = 1; i <= hp->count; i++) {
    tab = sqrt(hp->count - i + 1);
    for (int j = 0; j < tab; j++) printf("\t");

    printf("%d ", hp->heap[i]);
  }
  printf("\n");
    
}

void destroy_heap(heap_t* hp) {

}
