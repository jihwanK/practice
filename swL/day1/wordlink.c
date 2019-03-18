#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "doublyLinkedlist.h"
#include "word.h"

#define POINTWORD_FILENAME  "c:/data/pointword.txt"
#define POINTWORD_CNT 5  /* 포인트단어 개수 */
#define INPUT_MAX_CNT 10 /* 게임시 입력 제한횟수 */

typedef struct _pointWord {
	char pointW[POINTWORD_CNT][50];
	int pwCnt; 
}PointWord;

int pointWordRead(PointWord *pw); /* 포인트단어 입력 받아 저장하는 함수 */
void wordGame(PointWord *pw);  /* 끝말잇기 게임 처리 함수 */
void pointWordDisplay(PointWord *pw); /* 포인트단어 출력 함수 */
int wordAgree(List *lp, char *userWord); /* 끝말잇기 여부 확인 함수 */
int pointWordCheck(PointWord *pw, char *userWord);  /* 포인트단어와 일치여부 확인 함수 */
/*------------------------------------------------------------------------------
 main()함수
-------------------------------------------------------------------------------*/
int main()
{
	PointWord pointW;  /* 포인트단어 저장 구조체 변수 선언 */
	int res;  /* 포인트단어 저장 파일의 읽기처리에 정상 처리 여부를 리턴 받을 변수 */

    /* 포인트단어 읽어오기 */
	res = pointWordRead(&pointW);
	if (res){ /* 포인트단어 저장 파일읽기 실패 */
		printf("%s 파일 오픈 에러!!\n", POINTWORD_FILENAME);
		return 0;
	}

	/* 끝말잇기 게임 함수 호출 */
	wordGame(&pointW);

	getchar(); getchar();
	return 0;
}

/*------------------------------------------------------------------------------
포인트단어를 해당 파일로 부터 입력 받아 저장하는 함수
정상적으로 수행되면 0리턴 / 비정상 수행되면 1 리턴
-------------------------------------------------------------------------------*/

int pointWordRead(PointWord *pw)
{
	FILE *fp;
	int i;

	// TODO

	fclose(fp);  /* 파일 닫기 */
	return 0;    /* 파일 정상 처리 시 0 리턴 */
}

/*------------------------------------------------------------------------------
끝말잇기 게임 처리 함수
-------------------------------------------------------------------------------*/
void wordGame(PointWord *pw)
{
	List wlist;
	int  score = 0;             /* 게임 점수 저장 변수 */
	int  res;
	int  i;
	Word data = {"", 0};
	char tempWord[50];

	printf("** 끝말잇기 게임을 시작합니다 **\n\n");
	createList(&wlist);

	// TODO

	

	destroyList(&wlist);
	return;
}
/*------------------------------------------------------------------------------
사용자 입력 단어를 포인트단어와 비교하여 포인트 단어를 맞췄으면  1리턴
못맞추면 0리턴
맞춘 포인터 단어는 배열에서 제거 함
-------------------------------------------------------------------------------*/
int pointWordCheck(PointWord *pw, char *userWord)
{
	
	// TODO

	
	return 0;
}
/*------------------------------------------------------------------------------
입력단어 끝말잇기 여부 확인
이어지기 성공 : 1리턴 / 이어지기 실패 : -1리턴
-------------------------------------------------------------------------------*/
int wordAgree(List *lp, char *userWord)
{
	
	// TODO

	return 0;
}
/*------------------------------------------------------------------------------
포인트단어 출력 함수
-------------------------------------------------------------------------------*/
void pointWordDisplay(PointWord *pw)
{
	
	// TODO

		return;
}
