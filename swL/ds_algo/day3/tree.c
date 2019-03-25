#include <stdio.h>
#include "tree.h"

int PN[MAX + 1];
int CL[MAX + 1];
int CR[MAX + 1];
int cnt;

void create_tree(void) {
  int cnt = 0;
}

void DLR(int n) {
  int next = CR[n];

  printf("%d ", n);
  if (next == 0) 
}

int FND(int n) {
  while (PN[n] != 0) {
    n = PN[n];
  }
  return n;
}