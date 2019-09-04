#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX_VERTEX 100

typedef struct _node {
  int vertex;
  struct _node* next;
} node_t;

typedef struct {
  node_t* graph[MAX_VERTEX];
  int vertex_cnt;
  int edge_cnt;
} graph_t;

extern int visited[];
extern int queue[];
extern int front;
extern int rear;

void init_graph(graph_t* gp);
void output_graph(graph_t* gp);

int add_node(graph_t* gp, int v1, int v2);
void destroy_graph(graph_t* gp);

void start_BFS(graph_t* gp);
void BFS(graph_t* gp, int s);

#endif