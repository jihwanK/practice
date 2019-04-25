#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
	int id; 
	int type;
	int type_dir[3];
	
	int weight;
	int dir_from;

	struct _node *next;
} t_node;

#endif