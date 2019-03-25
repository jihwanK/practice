#include <stdio.h>

int cnt = 0;

void get_close(int dist) {
  if (dist == 0) {
    return;
  } else if (dist >= 10) {
    cnt++;
    get_close(dist - 10);
  } else if (dist >= 5) {
    cnt++;
    get_close(dist - 5);
  } else if (dist >= 1) {
    cnt++;
    get_close(dist - 1);
  } else {
    cnt++;
    get_close(dist + 1);
  }
}


int main(void) {
  int a , b, res;
  int test_case;

  freopen("data.txt", "r", stdin);
  scanf("%d", &test_case);

  for (int i = 0; i < test_case; i++) {
    scanf("%d %d", &a, &b);
    cnt = 0;
    if (a > b) {
      get_close(a - b);
    } else {
      get_close(b - a);
    }
    
    scanf("%d", &res);

    printf("my answer : (%d) <==> answer : (%d) \n", cnt, res);

  }

  
}