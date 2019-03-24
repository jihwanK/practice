#include <stdio.h>

#define MAX 20

char board[MAX][MAX];
int H, W;
int test_case;
int num_white;

int block_x[4][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int block_y[4][2] = { {1, 1}, {0, 1}, {0, 1}, {0, -1} };


typedef struct _coord {
  int row;
  int col;
} coord_t;


void init_problem() {
  num_white = 0;

  scanf("%d %d", &H, &W);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      board[i][j] = 0;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf(" %c", &board[i][j]);
      if (board[i][j] == '.') num_white++;
    }
  }
}

void print_board() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}


int in_range(coord_t cur) {
  return (cur.row < H && cur.col < W && cur.row >= 0 && cur.col >= 0);
}

int is_white_path(coord_t cur1, coord_t cur2, coord_t cur3) {
  return (board[cur1.row][cur1.col] == '.' && board[cur2.row][cur2.col] == '.' && board[cur3.row][cur3.col] == '.');
}

int solve(coord_t cur) {
  int res = 0;
  if (num_white == 0) return 1;
  // if (x >= H || y >= W || x < 0 || y < 0) return 0;

  for (int i = 0; i < 4; i++) {
    coord_t bc1 = { cur.row, cur.col };
    coord_t bc2 = { cur.row + block_x[i][0], cur.col + block_y[i][0] };
    coord_t bc3 = { cur.row + block_x[i][1], cur.col + block_y[i][1] };
    
    if (in_range(bc1) && in_range(bc2) && in_range(bc3) && is_white_path(bc1, bc2, bc3)) {
      board[bc1.row][bc1.col] = 'O';
      board[bc2.row][bc2.col] = 'O';
      board[bc3.row][bc3.col] = 'O';
      
    }
  }
  return res;
}


int main(void) {
  freopen("data_cover.txt", "r", stdin);
  scanf("%d", &test_case);

  for (int i = 0; i < test_case; i++) {
    init_problem();
    print_board();

    if (num_white % 3 != 0) {
      printf("%d \n", 0);
    } else {
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          solve(i, j);
        }
      }
    }
  }
}