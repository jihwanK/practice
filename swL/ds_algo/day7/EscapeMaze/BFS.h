#ifndef BFS_H_
#define BFS_H_

#define MAX 100 				/* �̷θ��� �ִ� ũ�� */
typedef struct _coord { 		/* �࿭ ��ǥ�� �����ϴ� ����ü */
	int row;
	int col;
} coord_t;

extern int map[][MAX + 1]; 		/* �� �迭 */
extern coord_t queue[];			/* �湮�������� ť */
extern int N; 					/* �� ���� �� */
extern int M; 					/* �� ���� �� */
extern coord_t start; 			/* ��� ��ǥ */
extern coord_t goal; 			/* ���� ��ǥ */
extern int front;				/* ť ��� �������� */
extern int rear;				/* ť �Է� �������� */
extern int dr[];				/* Ž����� ���� ��� ��ǥ */
extern int dc[];				/* Ž����� ���� �����ǥ */

void initMap(void);
void createMap(void);
void printMap(void);
int BFS(coord_t s, coord_t g);

#endif /* BFS_H_ */
