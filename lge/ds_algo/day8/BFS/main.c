#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100         	// ���� �ִ� ���� ���� ũ��
#define ROAD -1         	// ���� ǥ�� ��
#define WALL -2        		// �� ǥ�� ��

typedef struct {        	// ��ǥ ����ü
	int row;
	int col;
} coord_t;

struct {                	// �����ǥ ����� ����ü ����
	int row[4];
	int col[4];
	int dir;
} rc = {{-1, 0, 1, 0}, {0, -1, 0, 1}, 4 };

int gMap[MAX][MAX];     	// �� 2���� �迭
int gRow;               	// ���� ���� ũ��
int gCol;               	// ���� ���� ũ��
coord_t gStart;         	// ����� ��ǥ
coord_t gGoal;          	// ������ ��ǥ

coord_t queue[MAX * MAX];   // BFS Ž���� Queue
int front;                  // Queue ��� ���� ����
int rear;                   // Queue �Է� ���� ����

/* �� �ʱ�ȭ �Լ��ν� ���α׷� ���� �Ϸ� �� ȣ���Ѵ� */
void init(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			gMap[i][j] = -1;
		}
	}
	gRow = 0;
	gCol = 0;
}

/* �� ���� �Լ� */
void create(void) {
	int i;
	int j;
	char ch;

	scanf("%d %d", &gRow, &gCol);
	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			scanf(" %c", &ch);
			switch(ch) {
			case 'S':                   // ������� ���
				gMap[i][j] = ROAD;
				gStart.row = i;
				gStart.col = j;
				break;
			case 'G':                   // �������� ���
				gGoal.row = i;
				gGoal.col = j;
				gMap[i][j] = ROAD;
				break;
			case '.':                   // ������ ���
				gMap[i][j] = ROAD;
				break;
			default:                    // �� ���� ���
				gMap[i][j] = WALL;
				break;
			}
		}
	}
}

/* �ʺ�켱Ž�� (BFS) �Լ��ν� Ž�� ������� �μ��� �Ѵ�. */
void bfs(coord_t s) {
	queue[rear] = s;
	rear = ((rear + 1) % (MAX * MAX));
	gMap[s.row][s.col] = 0;

	while (front != rear) {
		coord_t tmp = queue[front];
		front = ((front + 1) % (MAX * MAX));

		if (tmp.row == gGoal.row && tmp.col == gGoal.col) {
			break;
		}
		
		for (int i = 0; i < rc.dir; i++) {
			int new_row = tmp.row + rc.row[i];
			int new_col = tmp.col + rc.col[i];
			coord_t new_tmp = {new_row, new_col};

			if (gMap[new_row][new_col] == ROAD) {
				gMap[new_row][new_col] = gMap[tmp.row][tmp.col] + 1;

				queue[rear] = new_tmp;
				rear = ((rear + 1) % (MAX * MAX));
			}
		}
	}
}

/* �� ��� �Լ� */
void print(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			switch (gMap[i][j]) {
			case ROAD:
				if ((gStart.row == i) && (gStart.col == j)) {
					printf(" S ");
				}
				else if ((gGoal.row == i) && (gGoal.col == j)) {
					printf(" G ");
				}
				else {
					printf(" . ");
				}
				break;
			case WALL:
				printf("%3c", '#');
				break;
			default:
				// printf("%c", 'O');
				printf("%3d", gMap[i][j]);
				break;
			}
		}
		printf("\n");
	}
}

int main(void) {
	int st, ed;

	freopen("data.txt", "r", stdin);        // ������ ���� ����

	create();                               // �� ����
	st = clock();                           // Ž�� �� �ð� ����
	bfs(gStart);                            // Ž�� ����
	ed = clock();                           // Ž�� �� �ð� ����

	print();                                // Ž�� �� �� ���
	
	// Ž�� ���� ���
	printf("�ִܰ�� : %d\n", gMap[gGoal.row][gGoal.col]);
	printf("Ž���ð� : %.6lf��\n", ((double)ed - st) / CLOCKS_PER_SEC);

	// ��� �迭 �� ���� �ʱ�ȭ
	init();

	return 0;
}