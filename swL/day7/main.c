#include <stdio.h>

int main() {

  int a= 3, b= 1, c = 0;

  c = a > b ? a : b;
  printf("%d \n", c);

  c = (a > b ? a : b) + 30;
  printf("%d \n", c);

  return 0;
}