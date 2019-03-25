#include <stdio.h>

#define MAX 10

int work[MAX + 1][MAX + 1];

int done[MAX + 1];
int result[MAX + 1];

int min_sum = 987654321;

void find_efficient_way(int idx, int len) {
  if (idx == len) {
    int sub_sum = 0;

    for (int i = 0; i < len; i++) {
      sub_sum += work[i+1][result[i]];
    }
    
    if (min_sum > sub_sum) min_sum = sub_sum;

    return ;
  }

  for (int i = 1; i <= len; i++) {
    if (done[i] == 0) {
      done[i] = 1;
      result[idx] = i;
      find_efficient_way(idx + 1, len);
      done[i] = 0;
    }
  }
}

int main(void) {
  freopen("data.txt", "r", stdin);

  int N = 0;
  int num = 0 ;

  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    min_sum = 987654321;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        scanf("%d", &work[i][j]);
      }
    }

    find_efficient_way(0, N);
    printf("%d \n", min_sum);
  }
  
  return 0;
}