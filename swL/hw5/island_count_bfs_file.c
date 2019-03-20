#include<stdio.h>
#include<assert.h>
#include "circularQueue.h"
#define MAX_SIZE 50
int a[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE][MAX_SIZE];
int dx[] = { 0, 0, 1,-1, 1, 1,-1,-1 };
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };
int w, h;  // 너비, 높이  저장변수
int dataLoad(FILE *);
bool inRange(int x, int y);
void bfs(int x, int y, int cnt);

int main()
{
	int cnt;
	FILE * fp;
	int i,j;
	fp = fopen("land.txt", "rt");
	assert(fp != NULL);

	while (1) {
		cnt = 0;
		if (dataLoad(fp) == false) {
			break;
		}
		for (i = 0; i<h; i++) {
			for (j = 0; j<w; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		printf("섬의 개수 : %d개\n", cnt);
	}
	fclose(fp);
	getchar();
	return 0;
}
//---------------------------------------------------------------------
void bfs(int x, int y, int cnt)
{
	Queue queue;
	int nx, ny;
	createQueue(&queue, w*h*2);

	enqueue(&queue, x);
	enqueue(&queue, y);
	d[x][y] = 1;

	while (isQueueEmpty(&queue)) {
		dequeue(&queue, &nx);
		dequeue(&queue, &ny);

		if (a[nx][ny] == 1) {
			int nnx, nny;

			for (int i = 0; i < 8; i++) {
				nnx = nx + dx[i];
				nny = ny + dy[i];

				if (a[nnx][nny] == 1 && d[nnx][nny] == 0) {
					enqueue(&queue, nnx);
					enqueue(&queue, nny);
					d[nnx][nny] = 1;
				}
			}
		}
	}

	destroyQueue(&queue);
}
//---------------------------------------------------------------------
int dataLoad(FILE *fp)
{
	int i, j; /* iterator */
	fscanf(fp, "%d %d", &w, &h);
	if (w == 0 && h == 0) return false;
	for (i = 0; i<h; i++) {
		for (j = 0; j<w; j++) {
			fscanf(fp, "%d", &a[i][j]);
			d[i][j] = 0;  // 사용여부 check 배열
		}
	}
	return true;
}
//---------------------------------------------------------------------
bool inRange(int x, int y)
{
	if (0 <= x && x < h && 0 <= y && y < w) {
		return true;
	}
	else{
		return false;
	}
}
