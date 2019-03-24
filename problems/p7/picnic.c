#include <stdio.h>

#define MAX 50

int test_case;
int num_students;
int num_pairs;

int pairs[MAX][MAX] = {0, };
int taken[MAX] = {0, };

void init_problem(void) {
  scanf("%d %d", &num_students, &num_pairs);

  for (int i = 0; i < num_students; i++) {
    for (int j = 0; j < num_students; j++) {
      pairs[i][j] = 0;
    }
  }

  for (int i = 0; i < num_pairs; i++) {
    int st1, st2;
    scanf("%d %d", &st1, &st2);
    printf("(%d %d) ", st1, st2);

    pairs[st1][st2] = 1;
    pairs[st2][st1] = 1;
  }
  printf("\n");
}

int solve() {
  int i ;
  int to_be_paired;
  int cnt = 0;

  for (i = 0; i < num_students; i++) {
    if (taken[i] == 0) {
      to_be_paired = i;
      break;
    }
  }

  if (i == num_students) {
    printf("\n");
    return 1;
  }

  for (int i = to_be_paired; i < num_students; i++) {
    if (pairs[to_be_paired][i] == 1 && taken[i] == 0) {
      taken[to_be_paired] = 1;
      taken[i] = 1;
      printf("(%d, %d) ", to_be_paired, i);
      cnt += solve();
      taken[i] = 0;
      taken[to_be_paired] = 0;
    }
  }

  return cnt;
}

void print_pairs() {
  for (int i = 0; i < num_students; i++) {
    for (int j = 0; j < num_students; j++) {
      printf("%d ", pairs[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  freopen("data_picnic.txt", "r", stdin);
  
  scanf("%d", &test_case);

  for (int i = 0; i < test_case; i++) {
    init_problem();

    print_pairs();
    printf("%d \n", solve());

    printf("================================\n");
  }

  

  return 0;
}