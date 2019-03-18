#include <stdio.h>
#include "graph.h"

int graph[MAX][MAX];
int vertex;
int edge;

void init_graph(void) {
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      graph[i][j] = 0;
    }
  }
}

void craete_graph(void) {
  char edges[2];
  
  for (int i = 0; i < edge; i++) {
    scanf("%s", edges);
    graph[edges[0]-'A'][edges[1]-'A'] = 1;
    graph[edges[1]-'A'][edges[0]-'A'] = 1;
  }
}

void print_graph(void) {
  printf("  ");
  for (int i = 0; i < vertex; i++) {
    printf("%c ", i + 'A');
  }
  printf("\n");

  for (int i = 0; i < vertex; i++) {
    printf("%c ", i + 'A');
    for (int j = 0; j < vertex; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}
