#include "graph.h"
#include <stdio.h>

int main(void) {
  freopen("data.txt", "r", stdin);
  scanf("%d %d", &vertex, &edge);

  init_graph();
  craete_graph();
  print_graph();

  startDFS();
  

  return 0;
}