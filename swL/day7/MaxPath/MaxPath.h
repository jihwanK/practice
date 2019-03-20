#ifndef MAXPATH_H_
#define MAXPATH_H_
#define MAX 10
#define UP 1
#define LEFT 2

extern int map[MAX + 1][MAX + 1];
extern int dir[MAX + 1][MAX + 1];
extern int N;

void initMap(void);
void createMap(void);
void printMap(void);
int calc(void);
void printDir(void);
void printPath(void);

#endif /* MAXPATH_H_ */
