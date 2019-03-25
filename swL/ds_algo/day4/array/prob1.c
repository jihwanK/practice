#include <stdio.h>

#define MAX 10

int main(void) {
  int N, M, W, H;
  int city[MAX][MAX];

  scanf("%d %d %d %d", &N, &M, &W, &H);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &city[i][j]);
    }
  }

  int max = 0;

  for (int i = 0; i < (N - W); i++) {
    for (int j = 0; j < (M - H); j++) {
      int sub_max = 0;

      for (int n = i; n < i + W; n++) {
        for (int m = j; m < j + H; m++) {
          sub_max += city[n][m];
        }
      }

      max = max < sub_max ? sub_max : max;
    }
  }
  printf("전체 구역의 최대 인구 수 : %d \n", max);

  return 0;
}