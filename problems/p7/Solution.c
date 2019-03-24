#include <stdio.h>

#define MAX 100

int N;
int M;

char words[MAX][MAX];
char boggle[MAX][MAX];

int dx[8] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dy[8] = { 1, -1, 1, -1, 0, 1, -1, 0 };

typedef struct _coord {
  int x;
  int y;
} coord_t;

void init_boggle() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++) {
    scanf("%s", words[i]);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf(" %c", &boggle[i][j]);
    }
  }
}

int has_word(coord_t cur, char word[]) {
  if (word[0] == '\0') { 
    return 1; 
  }

  for (int i = 0; i < 8; i++) {
    coord_t tmp = { cur.x + dx[i], cur.y + dy[i] };
    
    if (tmp.x >= N || tmp.y >= N || tmp.x < 0 || tmp.y < 0) { continue; }
    if (boggle[tmp.x][tmp.y] == word[0]) {
      // boggle[tmp.x][tmp.y] += 32;
      printf("boggle[%d][%d] = %c \n", tmp.x, tmp.y, boggle[tmp.x][tmp.y]);
      return has_word(tmp, word + 1);
    }
  }
  return 0;
}

void solve(char* word) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      coord_t start = { i, j };
      if (has_word(start, word)) {
        printf("%s is in here \n", word);
        return ;
      }
    }
  }
  
}

void print_boggle() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", boggle[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  
  freopen("data.txt", "r", stdin);

  init_boggle();

  printf("======BEFORE BOGGLE======\n");
  print_boggle();
  printf("=========================\n");
  
  for (int i = 0; i < M; i++) {
    solve(words[i]);
  }

  printf("======AFTER BOGGLE=======\n");
  print_boggle();
  printf("=========================\n");
  

}