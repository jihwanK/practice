#include "maze.h"
#include "a_star.h"
#include <math.h>
#include <stdlib.h>

#define INF (987654321)
#define NINF (-987654321)



int final_path[MAX_SIZE];


// closed_set *create_closed_node(t_node *node) {
//   closed_set *tmp = malloc(sizeof(closed_set));
//   tmp->node_ptr = node;
//   tmp->next = NULL;
//   return tmp;
// }


// open_set *create_open_node(t_node *node) {
//   open_set *tmp = malloc(sizeof(open_set));
//   tmp->node_ptr = node;
//   tmp->next = NULL;
//   return tmp;
// }


// closed_set *add_closed_node(closed_set *head, t_node *node_ptr) {
//   closed_set *new_node = create_closed_node(node_ptr);
//   closed_set *tmp;

//   if (head == NULL) {
//     head = new_node;
//   } else {
//     tmp = head;

//     while(tmp->next != NULL) {
//       tmp = tmp->next;
//     }
//     tmp->next = new_node;
//   }

//   return head;
// }



////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////




t_node *get_goal() {
  for(int i = 0; i < total_nodes; i++) {
    if (nodes[i]->id == -1) {
      return nodes[i];
    }
  }
}

int heuristic_manhattan (t_node *node) {
  t_node *goal = get_goal();
  int dx = (node->coor_x > goal->coor_x) ? node->coor_x : goal->coor_x;
  int dy = (node->coor_y > goal->coor_y) ? node->coor_y : goal->coor_y;

  return (dx + dy);
}

int heuristic_euclidean (t_node *node) {
  t_node *goal = get_goal();
  int dx = (node->coor_x > goal->coor_x) ? node->coor_x : goal->coor_x;
  int dy = (node->coor_y > goal->coor_y) ? node->coor_y : goal->coor_y;

  return (int) sqrt(pow(dx, 2) + pow(dy, 2));
}


int *reconstruct_path(int came_from[], t_node *cur) {
  int i = 1;
  int total_path[MAX_SIZE] = {cur->id};

  while(1);
}


// start node id == 0
// goal node id == -1
void a_star(t_node *start, t_node *goal) {
  t_node *closed_set[MAX_SIZE] = {0, };
  t_node *open_set[MAX_SIZE] = {start, };

  int closed_set_start = 0;
  int closed_set_end = 0;
  int num_closed_set_ele = closed_set_end - closed_set_start;

  int open_set_start = 0;
  int open_set_end = 1;
  int num_open_set_ele = open_set_end - open_set_start;

  // int lowest_open_idx;

  int came_from[MAX_SIZE];
  int g_score[MAX_SIZE];
  int f_score[MAX_SIZE];
  
  memset(g_score, INF, sizeof(int)*MAX_SIZE);
  g_score[0] = 0;

  memset(f_score, INF, sizeof(int)*MAX_SIZE);
  f_score[0] = heuristic_manhattan(nodes[0]);

  while (num_open_set_ele != 0) {
    t_node *cur;
    int cur_idx;

    for (int i = open_set_start; i < open_set_end; i++) {
      int min = INF;
      if (min > f_score[open_set[i]->id]) {
        min = f_score[open_set[i]->id];
        cur_idx = open_set[i]->id;
      }
    }

    cur = nodes[cur_idx];
    if (cur_idx == -1) {
      memcpy(final_path, reconstruct_path(came_from, cur), sizeof(int) * total_nodes);
    }

    

  }


}




int f(t_node node) {
  
}      