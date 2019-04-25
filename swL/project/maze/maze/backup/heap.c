#include "heap.h"


// the index of this heap is an id of each node

int heap[MAX_SIZE];
int h_size;

void init_heap() {
  h_size = 0;
  heap[0] = INF;
}
 
void insert_heap(int element) {
  h_size++;
  heap[h_size] = element;
  int now = h_size;

  while (heap[now / 2] > element) {
    heap[now] = heap[now / 2];
    now /= 2;
  }
  
  heap[now] = element;
}
 
int delete_min_heap() {
  int min_element, last_element, child, now;
  
  min_element = heap[1];
  last_element = heap[h_size--];

  for (now = 1; now * 2 <= h_size; now = child) {
    child = now * 2;
    
    if (child != h_size && heap[child + 1] < heap[child]) {
      child++;
    }

    if (last_element > heap[child]) {
      heap[now] = heap[child];
    } else {
      break;
    }
  }

  heap[now] = last_element;
  return min_element;
}




void insert_heap_fscore(int element, int fscore[]) {
  h_size++;
  heap[h_size] = element;
  int now = h_size;

  while (fscore[heap[now / 2]] > fscore[element]) {
    heap[now] = heap[now / 2];
    now /= 2;
  }
  
  heap[now] = element;
}


// returns the id of the node which has minimum f_score
int delete_min_heap_fscore(int fscore[]) {
  int min_element, last_element, child, now;
  
  min_element = heap[1];
  last_element = heap[h_size--];

  for (now = 1; now * 2 <= h_size; now = child) {
    child = now * 2;
    
    if (child != h_size && fscore[heap[child + 1]] < fscore[heap[child]]) {
      child++;
    }

    if (fscore[last_element] > fscore[heap[child]]) {
      heap[now] = heap[child];
    } else {
      break;
    }
  }

  heap[now] = last_element;
  return min_element;
}
 

