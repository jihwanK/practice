#include <stdio.h>
#include<string.h>

typedef enum { false, true } bool_t;

int string_size(char string[]) {
  int i = 0;
  while(string[++i] != '\0');
  return i;
}

int is_there_number(char num[], int start, int end) {
  for (int i = start; i < end; i++) {
    if (num[i] > '9' || num[i] < '0') {
      return -1;
    }
  }
  return 0;
}

int main(void) {
	int i;
	const char *smallUnit[] = { "십", "백", "천" };										// 소단위
	const char *bigUnit[] = { "만", "억", "조" };									// 대단위
	const char *number[] = { "일", "이", "삼", "사", "오", "육", "칠", "팔", "구" };		// 변환문자

	// TODO

  char num_string[100];
  char stack[100][10];
  int top = 0;
  int len = 0;

  int t_unit = 1;
  int s_unit = 0;


  // freopen("data2.txt", "r", stdin);

  scanf("%s", num_string);

  len = string_size(num_string);

  for (int i = len - 1; i >= 0; i--) {
    if (t_unit == 2 && num_string[i] != '0') {
      strcpy(stack[top], smallUnit[0]);
      top++;
    } else if (t_unit == 3 && num_string[i] != '0') {
      strcpy(stack[top], smallUnit[1]);
      top++;
    } else if (t_unit == 4 && num_string[i] != '0') {
      strcpy(stack[top], smallUnit[2]);
      top++;
    } else if (t_unit == 5 && (is_there_number(num_string, 5, 9) == 0 || len < 9 || num_string[i] != '0')) {
      strcpy(stack[top], bigUnit[0]);
      top++;
    } else if (t_unit == 9 && (is_there_number(num_string, 9, 13) == 0  || len < 13 || num_string[i] != '0')) {
      strcpy(stack[top], bigUnit[1]);
      top++;
    } else if (t_unit == 13 && (is_there_number(num_string, 13, 17) == 0 || len < 17 || num_string[i] != '0')) {
      strcpy(stack[top], bigUnit[2]);
      top++;
    } else if (t_unit > 5 && t_unit < 9) {
      if (len > 5 && len < 9 && num_string[i] != '0') {
        strcpy(stack[top], smallUnit[t_unit - 6]);
        top++;
      }
    } else if (t_unit > 9 && t_unit < 13) {
      if (len > 9 && len < 13 && num_string[i] != '0') {
        strcpy(stack[top], smallUnit[t_unit - 10]);
        top++;
      }
    } else if (t_unit > 13 && t_unit < 17) {
      if (len > 13 && len < 17 && num_string[i] != '0') {
        strcpy(stack[top], smallUnit[t_unit - 14]);
        top++;
      }
    }


    switch (num_string[i]) {
      case '0':
      t_unit++;
      break;
      case '1':
      strcpy(stack[top], number[0]);
      top++;
      t_unit++;
      break;
      case '2':
      strcpy(stack[top], number[1]);
      top++;
      t_unit++;
      break;
      case '3':
      strcpy(stack[top], number[2]);
      top++;
      t_unit++;
      break;
      case '4':
      strcpy(stack[top], number[3]);
      top++;
      t_unit++;
      break;
      case '5':
      strcpy(stack[top], number[4]);
      top++;
      t_unit++;
      break;
      case '6':
      strcpy(stack[top], number[5]);
      top++;
      t_unit++;
      break;
      case '7':
      strcpy(stack[top], number[6]);
      top++;
      t_unit++;
      break;
      case '8':
      strcpy(stack[top], number[7]);
      top++;
      t_unit++;
      break;
      case '9':
      strcpy(stack[top], number[8]);
      top++;
      t_unit++;
      break;
      default:
      break;
    }
  }

  for (int i = top - 1; i >= 0; i--) {
    printf("%s", stack[i]);
  }



	return 0;
}