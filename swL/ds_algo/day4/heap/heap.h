#ifndef HEAP_H_
#define HEAP_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _heap {
  int* heap;
  int size;
  int count;
} heap_t;

bool_t craete_heap(heap_t* hp, int size);
bool_t is_heap_empty(heap_t* hp);
bool_t is_heap_full(heap_t* hp);
bool_t insert_heap(heap_t* hp, int data);
bool_t delete_heap(heap_t* hp, int* get_data);
void up_heap(heap_t* hp, int child);
void down_heap(heap_t* hp, int parent);
void print_heap(const heap_t* hp);
void destroy_heap(heap_t* hp);

#endif