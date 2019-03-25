#ifndef FLOYD_H_
#define FLOYD_H_

#define MAX 10
#define INF 10000000
#define NIL -1

extern int d[MAX + 1][MAX + 1];
extern int p[MAX + 1][MAX + 1];
extern int vertex;
extern int edge;

void initGraph(void);
void createGraph(void);
void printGraph(void);
void floydWarshall(void);
void printDistance(void);
void printPredecessor(void);
void printPath(int s, int t);

#endif /* FLOYD_H_ */
