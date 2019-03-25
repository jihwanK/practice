#include <stdio.h>
#include "graph.h"

int graph[MAX][MAX];
int vertex;
int edge;
int visited[MAX];

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
    graph[edges[0] - 'A'][edges[1] - 'A'] = 1;
    graph[edges[1] - 'A'][edges[0] - 'A'] = 1;
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

void startDFS(void) {
  int num = 0;

  printf("\n");
  for (int i = 0; i < vertex; i++) {
    if (visited[i] != 1) {
      num++;
      printf("연결요소 %d : ", num);
      DFS(i);
      printf("\n");
    }
  }
  
  printf("그래프 내의 총 연결 요소의 개수 : %d \n", num);
}

void DFS(int u) {
  visited[u] = 1;
  printf("%c ", u + 'A');

  for (int i = 0; i < vertex; i++) {
    if ((visited[i] != 1) && (graph[u][i] == 1)) {
      DFS(i);
    }
  }
}
