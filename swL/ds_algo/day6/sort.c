#define SWAP(x, y, tmp) { tmp = x; x = y; y = tmp; } while(0)


/* int cmp1(int x, int y) { x > y; }
int cmp1(int x, int y) { x < y; }

void sort(int* arr, int len, int(*cmp)(int, int)) {
  int temp;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j <++) {
      if(cmp(arr[i], arr[j])) {
        SWAP(arr[i], arr[j], temp);
      }
    }
  }
} */

#include <stdio.h>

void generic_swap(void* a, void* b, int size) {
  char* p = (char*)a;
  char* q = (char*)b;

  char t;
  for (int i = 0; i < size; i++, p++, q++) {
    t = *p;
    *p = *q;
    *q = t;
  }
}

int cmp1(const void* x, const void* y) { return *(int*) x > *(int*) y; }
int cmp2(const void* x, const void* y) { return *(int*) x < *(int*) y; }

void sort(void* _arr, int len, int esize, int(*cmp)(const void*, const void*)) {
  char* arr = _arr;
  int temp;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if(cmp((arr + (i * esize)), (arr + (j * esize)))) {
        generic_swap(arr + i * esize, arr + j * esize, esize);
      }
    }
  }
}

int main(void) {
  int arr[5] = {5,4,3,2,1};
  
  sort(arr, 5, sizeof(int), cmp1);

  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  return 0;
}