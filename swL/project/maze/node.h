#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
	int id;
	int coor_x;
	int coor_y;
	int type_dir[4];
	
	int weight;
	int dir_from;

	struct _node *next;
} t_node;

#endif