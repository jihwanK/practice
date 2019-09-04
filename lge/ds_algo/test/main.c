#include <stdio.h>
#define MAX_COUNTER 2048
#define MAX_STRING 100
typedef enum _bool { false, true } bool_t;


bool_t is_in_the_patterns(char pattern[][100], char num[], int max_pattern, int len) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    cnt = 0;
    for (int j = 0; j < max_pattern; j++) {
      if (pattern[i][j] == num[j]) {
        cnt++;
      }
    }
    if (cnt == max_pattern){
      return true;
    }
  }
  return false;
}

int string_size(char string[]) {
  int i = 0;
  while(string[++i] != '\0');
  return i;
}

void print_patterns(char p[][100]) {
  for(int i = 0; i < 10; i++) {
    printf("%s \n", p[i]);
  }
}

int main(void) {	
  
  /***********************************/
  /***********************************/
  freopen("data.txt", "r", stdin);
  /***********************************/
  /***********************************/
  int cnt = 1;
  int max_pattern = 0;
  char num_string[MAX_STRING] = {0, }; 
  char patterns[MAX_STRING][MAX_STRING] = {0, };
  char tmp[MAX_STRING * MAX_STRING] = {0,};
  int len = 0;

  scanf("%d", &max_pattern);
  scanf("%s", num_string);

  len = string_size(num_string);

  for (int i = 0; i <= (len - max_pattern); i++) {
    for (int j = 0; j < max_pattern; j++) {
      tmp[j] = num_string[j + i];
    } 
    
    if (is_in_the_patterns(patterns, tmp, max_pattern, cnt) == false) {
      for (int j = 0; j < max_pattern; j++) {
        patterns[cnt-1][j] = tmp[j];
      }
      cnt++;
    }
  }

  printf("%d \n", cnt-1);
  
  // print_patterns(patterns);

	return 0;
}
