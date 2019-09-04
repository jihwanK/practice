#include <stdio.h>

int main(void) {
  int testcase = 0; 

  freopen("data.txt", "r", stdin);

  scanf("%d", &testcase);

  for (int i = 0; i < testcase; i++) {
    int node_a, node_b;
    int num_a = 0, num_b = 0;

    scanf("%d %d", &node_a, &node_b);

    while (node_a != node_b) {
      if (node_a > node_b) {
        node_a = node_a / 2;
        num_a++;
      } else {
        node_b = node_b / 2;
        num_b++;
      }
    }

    printf("%d \n", num_a + num_b);

  }
  return 0;
}