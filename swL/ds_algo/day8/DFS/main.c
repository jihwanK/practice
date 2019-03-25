#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100     // ���� ���� ���� �ִ� ũ��
#define ROAD -1     // ���� ǥ�� ��
#define WALL -2     // �� ǥ�� ��

// int all_cases[500];


typedef struct {    // ��ǥ ����ü
	int row;
	int col;
} coord_t;

struct {            // �����ǥ ����� ����ü ����
	int row[4];
	int col[4];
	int dir;
} rc = {{-1, 0, 1, 0}, {0, -1, 0, 1}, 4 };

int gMap[MAX][MAX]; // �� �迭
int gRow;           // ���� ���� ũ��
int gCol;           // ���� ���� ũ��
coord_t gStart;     // ��� ��
coord_t gGoal;      // ���� ��
int minV;           // ��������� ������������ �ּҰŸ� ���� ����
int maxV;           // ��������� ������������ �ִ�Ÿ� ���� ����
int rootCnt;        // ��������� ������������ ����� �� ���� ����

// �� �ʱ�ȭ �Լ�
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

// �� ���� �Լ�
void create(void) {
	int i;
	int j;
	char ch;

	scanf("%d %d", &gRow, &gCol);
	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			scanf(" %c", &ch);
			switch(ch) {
			case 'S':               // ������� ���
				gMap[i][j] = ROAD;
				gStart.row = i;
				gStart.col = j;
				break;
			case 'G':               // �������� ���
				gGoal.row = i;
				gGoal.col = j;
				gMap[i][j] = ROAD;
				break;
			case '.':               // ������ ���
				gMap[i][j] = ROAD;
				break;
			default:                // �� ���� ���
				gMap[i][j] = WALL;
				break;
			}
		}
	}
}

// ���� �켱 Ž�� (DFS) �Լ�
// ù ��° �μ� : Ž�� ��ǥ
// �� ��° �μ� : Ž�� �̵� Ƚ��
void dfs(coord_t s, int c) {

	if (s.row < 1 || s.col < 1 || s.row > gRow || s.col > gCol) {
		return;
	} else if (s.row == gGoal.row && s.col == gGoal.col) {
		if (c < minV) {
			minV = c;
		} else if (c > maxV) {
			maxV = c;
		}
		// all_cases[rootCnt] = c;
		rootCnt++;
		return;
	} else {
		for (int i = 0; i < rc.dir; i++) {
			int new_row = s.row + rc.row[i];
			int new_col = s.col + rc.col[i];

			if (gMap[new_row][new_col] == ROAD) {
				coord_t tmp = {new_row, new_col};
				gMap[new_row][new_col] = c;
				dfs(tmp, ++c);
				gMap[new_row][new_col] = ROAD;
				c--;
			}
		}
	}
	
}

// �� ��� �Լ�
void print(void) {
	int i;
	int j;

	for (i=1 ; i<=gRow ; i++) {
		for (j=1 ; j<=gCol ; j++) {
			switch (gMap[i][j]) {
			case ROAD:
				if ((gStart.row == i) && (gStart.col == j)) {
					printf("S");
				}
				else if ((gGoal.row == i) && (gGoal.col == j)) {
					printf("G");
				}
				else {
					printf(".");
				}
				break;
			case WALL:
				printf("%c", '#');
				break;
			default:
				break;
			}
		}
		printf("\n");
	}

	// for (int i = 0 ; i < 500; i++) {
	// 	printf("(%2d) %d \n", i, all_cases[i]);
	// }
}

int main(void) {
	int st, ed;

	freopen("data.txt", "r", stdin);    // ���� �Է� ����
	create();                           // �� ����

	minV = 10000;                       // �ּ� ��ΰ� ���� ���� �ʱ�ȭ
	maxV = 0;                           // �ִ� ��ΰ� ���� ���� �ʱ�ȭ
	rootCnt = 0;                        // �̵� ��� �� ���� �ʱ�ȭ

	st = clock();                       // Ž�� ���� �ð�
	dfs(gStart, 0);                     // DFS Ž�� ����
	ed = clock();                       // Ž�� ���� �ð�

	print();                            // �� �� Ž�� ���� ���
	printf("�ּҰ�� : %d\n", minV);
	printf("�ִ��� : %d\n", maxV);
	printf("��μ� : %d\n", rootCnt);
	printf("Ž���ð� : %.6lf��\n", ((double)ed - st) / CLOCKS_PER_SEC);
	
	init();                             // ��뺯�� �ʱ�ȭ

	return 0;
}
