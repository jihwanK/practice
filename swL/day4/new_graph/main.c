#include <stdio.h>
#include "graph.h"

int main(void) {
  graph_t Graph;

  freopen("data.txt", "r", stdin);
  

  init_graph(&Graph);
  output_graph(&Graph);

  // startDFS();
  

  return 0;
}