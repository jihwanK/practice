#include<stdio.h>
#define INF  1000

int d[101][101];  // �׷��� ���� ���� ����(���� ��Ĺ�)
int path[101][101];  // path ���� �迭 
int n;

void dataRead();
void printGraph(int (*p)[101]);

int main()
{
	dataRead();
	printGraph(d);
	int i,j,k;
	// floyd �˰���
	for (k=1; k<=n; k++) {  // k�� ������
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				if ( d[i][j] > d[i][k] + d[k][j] ) {
					d[i][j] = d[i][k] + d[k][j] ;
					path[i][j] = k;
				}
			}
		}
		printGraph(d);
	}
	printGraph(path);

	printPath(1,4);

	return 0;
}

void printPath(int s, int t)
{
	if(path[s][t] == 0){
		return;
	}
     //printf(" %d %d\n", s,t);
	printPath(s, path[s][t]);
    printf(" %d > ", path[s][t]);
	printPath(path[s][t], t);
	printf("**");
}
	
void dataRead()
{
	int i, j;
	freopen("data.txt", "rt", stdin);
	scanf("%d", &n);  // node�� ����  
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &d[i][j]);
			if(d[i][j]==0){
				d[i][j]=INF;
			}
		}
	}
}
void printGraph(int (*p)[101])
{
	int i, j;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) {
			printf("%5d", p[i][j]);
		}
		printf("\n");
	}
	printf("*------------------------*\n");
}
