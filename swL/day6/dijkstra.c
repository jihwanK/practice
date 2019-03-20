#include <stdio.h>
#include <stdlib.h>

#define MAX 10
enum { A, B, C, D, E, F, G, H, I, J };

int vertices;
int edges;
int visited[MAX];
int dist[MAX];
int predecessor[MAX];

void init_graph(int G[][MAX], int source) {

  /****************************************/

  scanf("%d %d", &vertices, &edges);

  for (int i = 0; i < edges; i++) {
    char ch1, ch2;
    int weight;
    scanf(" %c %c %d", &ch1, &ch2, &weight);
    G[ch1-'A'][ch2-'A'] = weight;
    G[ch2-'A'][ch1-'A'] = weight;
  }

  /****************************************/

  for (int i = 0; i < vertices; i++) {
    if (G[i][B] != 0) {
      predecessor[i] = B;
      dist[i] = G[i][B];
    } else {
      predecessor[i] = -1;
      dist[i] = 987654321;
    }
  }

  /****************************************/

}

void print_graph(int G[][MAX]) { 
  printf("[PRINT graph]\n");
  for (int i = 0; i < vertices; i++) {
    for (int j = 0 ; j < vertices; j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

void print_dist() {
  printf("[PRINT dist]\n");
  for (int i = 0; i < vertices; i++) {
    printf("%d ", dist[i]);
  }
  printf("\n");
}

void print_predecessor() {
  printf("[PRINT predecessor]\n");
  for (int i = 0; i < vertices; i++) {
    printf("%d ", predecessor[i]);
  }
  printf("\n");
}

void dikjstra(int G[][MAX], int _source) {
  init_graph(G, _source);

  for (int i = 0; i < vertices; i++) {

  }

}


int main(void) {
  freopen("dijkstra_data.txt", "r", stdin);

  int G[MAX][MAX] = {0, };

  dikjstra(G, B);

  print_graph(G);
  printf("\n");
  print_dist();
  printf("\n");
  print_predecessor();
  printf("\n");


  return 0;
}