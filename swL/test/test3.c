#include <stdio.h>
#define MAX 100

// TODO - 필요한 extern 메모리 정의

typedef struct _coord {
  int row;
  int col;
} coord_t;


int N, M ;
int original_apple[MAX][MAX];
int apples[MAX][MAX];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

coord_t q[MAX * MAX];
coord_t start[MAX];
int num_start = 0;
int front;
int rear;

int days;




void get_start_points() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (apples[i][j] == 1) {
        coord_t tmp = {i, j};
        start[num_start++] = tmp;
      }
    }
  }
  // printf("%d", num_start);
}



int check_box() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (apples[i][j] == 0) {
        return -1;
      }
    }
  }
  return 0;
}

int get_answer() {
  int max = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      max = max > apples[i][j] ? max : apples[i][j];
    }
  }
  return max;
}

int bfs() {
  get_start_points();

  for (int i = 0; i < num_start; i++) {
    q[rear] = start[i];
    rear++;
    apples[start[i].row][start[i].col] = 2;
    // printf ("( %d, %d )", start[i].row, start[i].col);
  }
  
  while(rear != front) {
    coord_t tmp = q[front];
    front++;

    for (int i = 0; i < 4; i++) {
      coord_t new_tmp = { tmp.row + dr[i], tmp.col + dc[i] };

      if (new_tmp.col < 0 || new_tmp.row < 0 || new_tmp.col >= M || new_tmp.row >= N) 
        continue;

      if (apples[new_tmp.row][new_tmp.col] == 0) {
        apples[new_tmp.row][new_tmp.col] = apples[tmp.row][tmp.col] + 1;
        q[rear] = new_tmp;
        rear++;
      }
      
    }
  }

  if (check_box() == -1) {
    return -1;
  } else if (check_box() == 0) {
    days = get_answer();
    return 0;
  }

}


void print_apples () {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%3d", apples[i][j]);
      // printf("%3d", original_apple[i][j]);
    }
    printf("\n");
  }
}

void init_apples () {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      apples[i][j] = original_apple[i][j];
    }
  }
}


int main(void) {
  int min = 987654321;

  freopen("data3.txt", "r", stdin);

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &apples[i][j]);
      original_apple[i][j] = apples[i][j];
    }
  }

  // print_apples();

  init_apples();

  if (bfs() == -1) {
    printf("%3d \n", 0);
    // break;
  } else {
    min = (min > days ? days : min) - 2;
    printf("%3d \n", min);
    // break;
  }


  // print_apples();

	
	// TODO
	return 0;
}

