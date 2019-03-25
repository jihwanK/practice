#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "doublyLinkedlist.h"
#include "word.h"

#define POINTWORD_FILENAME  "c:/data/pointword.txt"
#define POINTWORD_CNT 5  /* ����Ʈ�ܾ� ���� */
#define INPUT_MAX_CNT 10 /* ���ӽ� �Է� ����Ƚ�� */

typedef struct _pointWord {
	char pointW[POINTWORD_CNT][50];
	int pwCnt; 
}PointWord;

int pointWordRead(PointWord *pw); /* ����Ʈ�ܾ� �Է� �޾� �����ϴ� �Լ� */
void wordGame(PointWord *pw);  /* �����ձ� ���� ó�� �Լ� */
void pointWordDisplay(PointWord *pw); /* ����Ʈ�ܾ� ��� �Լ� */
int wordAgree(List *lp, char *userWord); /* �����ձ� ���� Ȯ�� �Լ� */
int pointWordCheck(PointWord *pw, char *userWord);  /* ����Ʈ�ܾ�� ��ġ���� Ȯ�� �Լ� */
/*------------------------------------------------------------------------------
 main()�Լ�
-------------------------------------------------------------------------------*/
int main()
{
	PointWord pointW;  /* ����Ʈ�ܾ� ���� ����ü ���� ���� */
	int res;  /* ����Ʈ�ܾ� ���� ������ �б�ó���� ���� ó�� ���θ� ���� ���� ���� */

    /* ����Ʈ�ܾ� �о���� */
	res = pointWordRead(&pointW);
	if (res){ /* ����Ʈ�ܾ� ���� �����б� ���� */
		printf("%s ���� ���� ����!!\n", POINTWORD_FILENAME);
		return 0;
	}

	/* �����ձ� ���� �Լ� ȣ�� */
	wordGame(&pointW);

	getchar(); getchar();
	return 0;
}

/*------------------------------------------------------------------------------
����Ʈ�ܾ �ش� ���Ϸ� ���� �Է� �޾� �����ϴ� �Լ�
���������� ����Ǹ� 0���� / ������ ����Ǹ� 1 ����
-------------------------------------------------------------------------------*/

int pointWordRead(PointWord *pw)
{
	FILE *fp;
	int i;

	// TODO

	fclose(fp);  /* ���� �ݱ� */
	return 0;    /* ���� ���� ó�� �� 0 ���� */
}

/*------------------------------------------------------------------------------
�����ձ� ���� ó�� �Լ�
-------------------------------------------------------------------------------*/
void wordGame(PointWord *pw)
{
	List wlist;
	int  score = 0;             /* ���� ���� ���� ���� */
	int  res;
	int  i;
	Word data = {"", 0};
	char tempWord[50];

	printf("** �����ձ� ������ �����մϴ� **\n\n");
	createList(&wlist);

	// TODO

	

	destroyList(&wlist);
	return;
}
/*------------------------------------------------------------------------------
����� �Է� �ܾ ����Ʈ�ܾ�� ���Ͽ� ����Ʈ �ܾ ��������  1����
�����߸� 0����
���� ������ �ܾ�� �迭���� ���� ��
-------------------------------------------------------------------------------*/
int pointWordCheck(PointWord *pw, char *userWord)
{
	
	// TODO

	
	return 0;
}
/*------------------------------------------------------------------------------
�Է´ܾ� �����ձ� ���� Ȯ��
�̾����� ���� : 1���� / �̾����� ���� : -1����
-------------------------------------------------------------------------------*/
int wordAgree(List *lp, char *userWord)
{
	
	// TODO

	return 0;
}
/*------------------------------------------------------------------------------
����Ʈ�ܾ� ��� �Լ�
-------------------------------------------------------------------------------*/
void pointWordDisplay(PointWord *pw)
{
	
	// TODO

		return;
}
