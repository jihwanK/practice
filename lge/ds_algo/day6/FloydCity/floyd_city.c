#include<stdio.h>

int d[101][101];  // �׷��� ���� ���� ����(���� ��Ĺ�)
int n; // ������ ����

int fileLoad(FILE *fp)
{
	int i, j;
	fscanf(fp, "%d", &n);
	if(n==0)
		return 0;

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			fscanf(fp, "%d", &d[i][j]);

	printf("vertex count : %d\n", n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			printf("%3d", d[i][j]);
		}
		printf("\n");
	}
	printf("*------------------------*\n");
	return 1;
}

int main()
{
	FILE *fp;
	int i,j,k;
	if ((fp = fopen("floyd_city.txt", "rt")) == NULL)
		return 0;

	while(fileLoad(fp)){
		// floyd �˰�����
        // TODO
	}
	fclose(fp);
	getchar();
	return 0;
}