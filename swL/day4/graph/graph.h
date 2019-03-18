#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX 100

extern int graph[MAX][MAX];
extern int vertex;
extern int edge;
extern int visited[MAX];

void init_graph(void);
void craete_graph(void);
void print_graph(void);
void startDFS(void);
void DFS(int u);

#endif