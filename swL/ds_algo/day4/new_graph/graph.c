#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int visited[MAX_VERTEX];
int queue[MAX_VERTEX];
int front;
int rear;


void init_graph(graph_t* gp) {
  scanf("%d %d", &gp->vertex_cnt, &gp->edge_cnt);
  for (int i = 0; i < gp->vertex_cnt; i++) {
    gp->graph[i] = NULL;
  }

  for (int i = 0; i < gp->edge_cnt; i++) {
    char edge[2];
    scanf("%s", edge);
    add_node(gp, edge[0]-'A', edge[1]-'A');
  }
}

void output_graph(graph_t* gp) {
  for (int i = 0; i < gp->vertex_cnt; i++) {
    node_t* cur = gp->graph[i]->next;

    while (cur != NULL) {
      printf("%c > ", (cur->vertex + 'A'));
      cur = cur->next;
    }

    printf("\n");
  }
}

int add_node(graph_t* gp, int v1, int v2) {
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->next = NULL;
  new_node->vertex = v2;

  if (new_node == NULL) return -1;

  if (gp->graph[v1] != NULL) {
    new_node->next = gp->graph[v1];
  }
  gp->graph[v1] = new_node;

  return 0;
}

void destroy_graph(graph_t* gp) {

}

void start_BFS(graph_t* gp) {

}

void BFS(graph_t* gp, int s) {

}
