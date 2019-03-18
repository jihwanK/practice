#ifndef BST_H_
#define BST_H_

typedef struct _node {
  int data;
  struct _node* left_child;
  struct _node* right_child;
} node_t;

typedef struct _tree {
  node_t* root;
  int node_cnt;
} BST;

void init_tree(BST* bp);
node_t* make_node(int data);
node_t* add_node(BST* bp, int data);
void inorder_traverse(node_t* np);
void preorder_traverse(node_t* np);
void postorder_traverse(node_t* np);
node_t* search_node(BST* bp, int data);
node_t* delete_node(BST* bp, int data);
void destroy_tree(BST* bp);
void postorder_delete(node_t* np);


#endif