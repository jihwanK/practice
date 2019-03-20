#include <stdio.h>
#include <stdlib.h>

int binary_search(long* arr, int target, int len, int start, int end) {
  int mid = (start + end) / 2;

  if (start == end && arr[start] != target) {
    printf("cannot find! -- ");
    return -1;
  }

  if (arr[mid] > target) {
    binary_search(arr, target, len, start, mid - 1);
  } else if (arr[mid] < target) {
    binary_search(arr, target, len, mid + 1, end);
  } else {
    printf("found! -- ");
    return arr[mid];
  }
  
}

int main(void) {
  long* arr = (long*) malloc(sizeof(long) * 100000000);
  // long long arr[10] = {1,2,3,4,5,6,7,8,9};

  for (long i = 0; i < 100000000; i++)
    arr[i] = i+1;

  for (int i = -10; i <= 20; i++) {
    printf("looking for [%d] -- ", i);
    int res = binary_search(arr, i, 10, 0, 9);
    printf("%d \n", res);
  }
  
  return 0;
} 