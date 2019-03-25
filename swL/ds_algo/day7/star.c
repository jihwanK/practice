#include <stdio.h>


void induction_star(int n) {
  if (n == 0) {
    return;
  }

  induction_star(n-1);

  for (int i = 0; i < n; i++) {
    printf("*");
  }
  printf("\n");
}

int main(void) {

  induction_star(180);
  return 0;
}