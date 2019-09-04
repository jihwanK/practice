#include "maze.h"
#include <stdio.h>

int is_within_error_range(int stand, int cmp) {
	if ((stand >= (cmp - TOL)) && (stand <= (cmp + TOL)))
		return TRUE;
	else
		return FALSE;
}

//////////////////////////////////////////////////////////

int is_dead_end(t_node *node) {
	return 1;
}

int is_end_node(t_node *node) {
	return 1;
}

///////////////////////////////////////////////////////////


int is_new_node(int x, int y) {
	for (int i = 0; i < total_nodes; i++)
		if ((is_within_error_range(nodes[i]->coor_x, x)) && (is_within_error_range(nodes[i]->coor_y, y)))
			return FALSE;
	return TRUE;
}

t_node *get_node(int x, int y) {
	for (int i = 0; i < total_nodes; i++)
		if ((is_within_error_range(nodes[i]->coor_x, x)) && (is_within_error_range(nodes[i]->coor_y, y)))
			return nodes[i];
	return NULL;
}

int add_node(int x, int y, int *type_dir, int dir_from) {
	t_node *node;
	
	if (is_new_node(x, y)) {
		node = malloc(sizeof(t_node));

		node->id = total_nodes;
		node->coor_x = x;
		node->coor_y = y;
		// node->type = type;
		node->dir_from = dir_from;
		// node->explored = 1;

		total_nodes += 1;
		nodes[total_nodes - 1] = node;
	} else {
		node = get_node(x, y);
		if (node == NULL) {
			fprintf(stderr, "cannot find nodes \n");
			return -1;
		}

		if (node->type > node->explored)
			node->explored += 1;
	}

	history[total_nodes - 1] = node;
	return 0;
}


int push(t_node* node) {
	if (top < MAX_SIZE) {
		Stack[top] = node;
		top++;
	}
}


int is_exploration_done() {
	for(int i = 0; i < total_nodes; i++) {
		if (nodes[i]->type > nodes[i]->explored)
		return FALSE;
	}
	return TRUE;
}


int make_graph() {
	while (1) {
		if (is_exploration_done()) break;

		t_node* node = add_node(coor_x, coor_y, get_type(), direction);

		if (is_dead_end(node)) {
			;
		} else {
			;
		}
	}
}
