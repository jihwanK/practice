#ifndef _MAZE_H_
#define _MAZE_H_

#define MAX_SIZE (1024)

#define TOL		(0.5)

#define TRUE	(1)
#define FALSE (0)

#define NORTH	(1)
#define SOUTH	(2)
#define EAST	(3)
#define WEST	(4)


/***************************/
/* structures */
/***************************/

typedef struct _node {
	int id;
	int coor_x;
	int coor_y;
	// int type;
	// int explored;
	int type_dir[4];
	
	int weight;
	int dir_from;
	// int dir_to;

	struct _node *next;
} t_node;

typedef struct _graph {
	int num_nodes;
	t_node **list;
} Graph;

/***************************/


/***************************/
/* variables */
/***************************/

extern int total_nodes;

extern int direction; // global in main
extern int coor_x; // global in main
extern int coor_y; // global in main

extern t_node *nodes[MAX_SIZE];
extern t_node *history[MAX_SIZE];

extern int top;
extern t_node *Stack[MAX_SIZE];

/***************************/


/***************************/
/* functions */
/***************************/

int is_within_error_range(int, int);
int is_new_node(int, int);
t_node *get_node(int, int);
int add_node(int, int, int*, int);

int is_exploration_done();

int push(t_node*);

int is_dead_end(t_node*);
int is_end_node(t_node*);

int get_type(); // how many routes the node has
int make_graph();

/***************************/

#endif
