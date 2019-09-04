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


void printUserword(List* lp);


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


	strcpy(pointW.pointW[0], "tiger");
	strcpy(pointW.pointW[1], "hen");
	strcpy(pointW.pointW[2], "cow");
	strcpy(pointW.pointW[3], "rabbit");
	strcpy(pointW.pointW[4], "lion");
	pointW.pwCnt = 5;



	// int res;  /* ����Ʈ�ܾ� ���� ������ �б�ó���� ���� ó�� ���θ� ���� ���� ���� */

  //   /* ����Ʈ�ܾ� �о���� */
	// res = pointWordRead(&pointW);
	// if (res){ /* ����Ʈ�ܾ� ���� �����б� ���� */
	// 	printf("%s ���� ���� ����!!\n", POINTWORD_FILENAME);
	// 	return 0;
	// }

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

	makeWord(&data, "pointer");
	addFirst(&wlist, data);

	// TODO
	for (i = 0; i < INPUT_MAX_CNT; i++) {
		pointWordDisplay(pw);
		printUserword(&wlist);
		printf("�����ձ� �ܾ� �Է�(%dȸ��)", i);
		scanf("%s", tempWord);
	}
	
	pointWordDisplay(pw);

	

	destroyList(&wlist);
	return;
}

void printUserword(List* lp) {
	Node* cur = lp->head->next;

	printf("����� �Է� �ܾ� : ");
	while (cur != lp->tail) {
		printf("%s(%d)/", cur->data.word, cur->data.len);
	}
	cur = cur->next;
}

/*------------------------------------------------------------------------------
����� �Է� �ܾ ����Ʈ�ܾ�� ���Ͽ� ����Ʈ �ܾ ��������  1����
�����߸� 0����
���� ������ �ܾ�� �迭���� ���� ��
-------------------------------------------------------------------------------*/
int pointWordCheck(PointWord *pw, char *userWord)
{
	
	// TODO
	for (int i = 0; i < pw->pwCnt; i++) {
		if (strcmp(pw->pointW[i], userWord) == 0) {
			strcpy(pw->pointW[i], "0");
			return 1;
		}
	}

	return 0;
}
/*------------------------------------------------------------------------------
�Է´ܾ� �����ձ� ���� Ȯ��
�̾����� ���� : 1���� / �̾����� ���� : -1����
-------------------------------------------------------------------------------*/
int wordAgree(List *lp, char *userWord)
{
	
	// TODO
	Word* data = (Word*) malloc(sizeof(Word));
	makeWord(data, userWord);
	// strcpy(data.word, userWord);
	// data.len = strlen(userWord);

	if (addLast(lp, *data) == TRUE) {
		return 1;
	} else {
		return -1;
	}

}
/*------------------------------------------------------------------------------
����Ʈ�ܾ� ��� �Լ�
-------------------------------------------------------------------------------*/
void pointWordDisplay(PointWord *pw)
{
	// TODO
	printf("\n* ����Ʈ �ܾ� : ");
	for (int i = 0; i < pw->pwCnt; i++) {
		printf("%s /", pw->pointW);
	}
	return;
}
