#ifndef _A_STAR_H_
#define _A_STAR_H_

#include "node.h"


/* structures */

// typedef struct _closed {
//   t_node *node_ptr;
//   struct _closed* next;
// } closed_set;

// typedef struct _open {
//   t_node *node_ptr;
//   struct _open* next;
// } open_set;



/* variables */ 

extern t_node *start;
extern t_node *goal;



/* functions */

// closed_set *create_closed_node(t_node *node);

// open_set *create_open_node(t_node *node);

// int add_node(closed_set *closed, t_node *node_ptr) ;

#endif