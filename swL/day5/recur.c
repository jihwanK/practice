#include <stdio.h>


void print_arr(int* arr, int len, int idx) {
  if (idx == len) return;
  
  printf("[%2d] ", arr[idx]);
  print_arr(arr, len, idx+1);
}

void print_arr_rev(int* arr, int len, int idx) {
  if (idx == len) return;
  
  print_arr_rev(arr, len, idx+1);
  printf("[%2d] ", arr[idx]);
}

void print_arr_reverse(int* arr, int idx) {
  if (idx == 0) return;
  
  printf("[%2d] ", arr[idx-1]);
  print_arr_reverse(arr, idx-1);
}

int main(void) {
  int arr[5] = { 1, 2, 3, 4, 5 };

  print_arr(arr, 5, 0);
  printf("\n");
  print_arr_rev(arr, 5, 0);
  printf("\n");
  print_arr_reverse(arr, 5);
}