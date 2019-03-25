#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void pattern_check(char *bstr, unsigned int pattern_length);
/*-----------------------------------------------------------------------
*   main() 함수
*---------------------------------------------------------------------*/
int main() {
	// 문자열로 저장된 2진 비트열 저장 배열
	char str[5][100] = { "44123144123144123114",
		"2324241231222412432311141413212422133213",
		"111421444443121432214221214111114423112342114411313211114432",
		"33334123333442243",
		"3333" };
	int size = sizeof(str) / sizeof(str[0]);
	int pattern_length;
	int i;

	printf("* 검사할 문자열의 길이를 입력하시오 (1~7) : ");
	scanf("%d", &pattern_length);

	for (i = 0; i < size; i++) {
		pattern_check(str[i], pattern_length); // 각 문자열의 패턴을 검사하고 결과를 출력하는 함수 호출
	}
	getchar();  getchar();

	return 0;
}
/*-----------------------------------------------------------------------
*  pattern_check() 함수 : 문자열의 패턴을 검하고 결과를 출력하는 함수
*  전달인자 : bstr - 문자열로 저장된 숫자열
plength - 패턴길이
*---------------------------------------------------------------------*/
void pattern_check(char *bstr, unsigned int plength) {

	// TODO
	return;
}
