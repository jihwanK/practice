#include <stdio.h>

/*******************************************/
/* int __find(int* arr, int len, int target, int idx)  {
  if (idx == len) return -1;
  if (arr[idx] == target) {
    return idx;
  }

  __find(arr, len, target, idx + 1);
}

int find(int* arr, int len, int target) {
  return __find(arr, len, target, 0);
} */
/*******************************************/


/*******************************************/
/* void __copy_arr(int* dst, int* src, int len, int idx) {
  if (idx == len) return;

  dst[idx] = src[idx];
  __copy_arr(dst, src, len, idx + 1);
}

void copy_arr(int* dst, int* src, int len) {
  __copy_arr(dst, src, len, 0);
} */
/*******************************************/


/*******************************************/
/* void print_arr(int* arr, int len, int idx) {
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
} */
/*******************************************/


/*******************************************/
/* #define MAX 3

int arr[MAX];
int used[MAX + 1];

void print_arr(void) {
  for (int i = 0; i < MAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void f(int idx, int len) {
  if (idx == len) {
    print_arr();
    return;
  }

  for (int i = 1; i <= MAX; i++) {
    if (used[i] == 0) {
      used[i] = 1;
      arr[idx] = i;
      f(idx + 1, len);  
      used[i] = 0;
    }
  }
} */
/*******************************************/


/*******************************************/
/* #define MAX 10

int min_dist = 987654321;
int dist[MAX + 1][MAX + 1];
int locations[MAX + 1][2];

int visited[MAX + 1];


int tarvel_to_friends(int idx, int M, int sub_sum) {
  if (idx == M) {
    if (sub_sum < min_dist) {
      min_dist = sub_sum;
      return min_dist;
    }

    for (int i = 0; i <= M; i++) {
      if (visited[i] == 0) {
        visited[i] = 1;
        sub_sum += dist[idx][i];
        tarvel_to_friends(idx + 1, M, sub_sum);
        visited[i] = 0;
      }
    }
  }
} */
/*******************************************/


/*******************************************/

void quicksort(int arr[], int left, int right) {
  int pivot = arr[right];
  int new_left = left, new_right = right;

  while (1) {
    if (pivot > arr[new_left]) new_left++;
    if (pivot < arr[new_right]) new_right--;
    if (pivot <= arr[new_left] && pivot >= arr[new_right]) {
      int tmp = arr[new_right];
      arr[new_right] = arr[new_left];
      arr[new_left] = tmp;
    }

    if (new_left >= new_right) {
      // int tmp = pivot;
      arr[right] = arr[new_left];
      arr[new_left] = pivot;

      quicksort(arr, 0, new_left - 1);
      quicksort(arr, new_left + 1, new_right);
      return;
    }
  }
}

void output(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d ", arr[i]);
  }
  printf("\n");
}


int main(void) {
  int data_list[] = { 76, 12, 53, 3, 15, 6, 34, 29, 25 };
  int size = sizeof(data_list) / sizeof(data_list[0]);

  printf("****** 정렬 전 출력 ******* \n");
  output(data_list, size);
  quicksort(data_list, 0, size - 1);
  printf("****** 정렬 후 출력 ******* \n");
  output(data_list, size);

  return 0;
}