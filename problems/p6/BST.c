#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void init_tree(BST* bp) {
  bp->node_cnt = 0;
  bp->root = NULL;
}

node_t* make_node(int data) {
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  if (new_node == NULL) return NULL;

  new_node->data = data;
  new_node->left_child = NULL;
  new_node->right_child = NULL;
  
  return new_node;
}

node_t* add_node(BST* bp, int data) {
  if (bp == NULL) return NULL;
  node_t* new_node = make_node(data);
  node_t* cur = bp->root;
  if (new_node == NULL) return NULL;

  if (bp->root == NULL) {
    bp->root = new_node;
    bp->node_cnt++;
    return new_node;
  }

  while (1) {
    if (new_node->data < cur->data) {
      if (cur->left_child == NULL) {
        cur->left_child = new_node;
        break;
      }
      cur = cur->left_child;
    } else {
      if (cur->right_child == NULL) {
        cur->right_child = new_node;
        break;
      }
      cur = cur->right_child;
    }
  }

  bp->node_cnt++;

  return cur;
}

void inorder_traverse(node_t* np) {
  if (np == NULL) return;

  inorder_traverse(np->left_child);
  printf("%d ", np->data);
  inorder_traverse(np->right_child);
}

void preorder_traverse(node_t* np) {
  if (np == NULL) return;
  
  printf("%d ", np->data);
  preorder_traverse(np->left_child);
  preorder_traverse(np->right_child);
}

void postorder_traverse(node_t* np) {
  if (np == NULL) return;

  postorder_traverse(np->left_child);
  postorder_traverse(np->right_child);
  printf("%d ", np->data);
}



/*************************************************************************/
/*************************************************************************/
/*************************************************************************/



node_t* search_node(BST* bp, int data) {
  node_t* cur = bp->root;

  while ((cur != NULL) && (cur->data != data)) {
    if (data < cur->data) {
      cur = cur->left_child;
    } else if (data > cur->data) {
      cur = cur->right_child;
    }
  }
  return cur;
}

node_t* search_parent(BST* bp, int data) {
  node_t* parent = NULL;
  node_t* cur = bp->root;

  while ((cur != NULL) && (cur->data != data)) {
    if (data < cur->data) {
      parent = cur;
      cur = cur->left_child;
    } else if (data > cur->data) {
      parent = cur;
      cur = cur->right_child;
    }
  }
  return parent;
}


// node_t* inorder_delete(node_t* np) {
//   if (np == NULL) return NULL;

//   inorder_delete(np->left_child);
//   inorder_delete(np->right_child);

//   return np;
// }


int deleteNode(BST* bp, int data) {
  /*
    (1) tree의 첫노드 부터 하위 level로 내려가면서 삭제할 노드 검색
        삭제할 노드의 parent 노드와 하위 노드를 연결을 해줘야 하므로 검색 시 parent 노드의 값도 구해야 함
    (2) 삭제된 노드 대신 parent노드의 새로운 자식(son) 역할을 할 노드 결정하기
    (2-1) 유형1 : 삭제할 노드의 자식이 2개 인 경우 (왼쪽 서브트리에서 대체노드 찾음)
    (2-2) 유형2 : 삭제노드의 자식이 없는 경우
    (2-3) 유형3 : 삭제할 노드의 자식이 1개 인 경우
  */

  if (bp == NULL) return -1;
  if (bp->root == NULL) return -1;

  node_t* delete_parent = search_parent(bp, data);
  node_t* delete_node = search_node(bp, data);
  node_t* alternative_parent;
  node_t* alternative;

  if ((delete_node->left_child != NULL) && (delete_node->right_child != NULL)) {
      // if there are two children for the node to be deleted

    alternative_parent = delete_node;
    alternative = delete_node->left_child;

    while (alternative->right_child != NULL) {
      alternative_parent = alternative;
      alternative = alternative->right_child;
    }

    // if ((alternative->left_child != NULL) && (alternative->right_child == NULL)) {



      delete_node->data = alternative->data;

      if (delete_parent->left_child == delete_node) {
        delete_parent->left_child = alternative;
      } else if (delete_parent->right_child == delete_node) {
        delete_parent->right_child = alternative;
      } 

      alternative->right_child = delete_node->right_child;
      free(delete_node);

    // } 
    // else if ((alternative->left_child == NULL) && (alternative->right_child == NULL)) {
    //   delete_node->data = alternative->data;
    //   alternative_parent->left_child == NULL;
    //   free(alternative);
    // }
    
  } else if ((delete_node->left_child == NULL) && (delete_node->right_child != NULL)) {
    // if there's one child for the node to be deleted

    if (delete_parent->left_child == delete_node) {
      delete_parent->left_child = delete_node->right_child;
      free(delete_node);
    } else if (delete_parent->right_child == delete_node) {
      delete_parent->right_child = delete_node->right_child;
      free(delete_node);
    }
  } else if ((delete_node->right_child == NULL) && (delete_node->left_child != NULL)) {
      // if there's one child for the node to be deleted
    
    if (delete_parent->left_child == delete_node) {
      delete_parent->left_child = delete_node->left_child;
      free(delete_node);
    } else if (delete_parent->right_child == delete_node) {
      delete_parent->right_child = delete_node->left_child;
      free(delete_node);
    }
  } else {
      // if there's no child for the node to be deleted

      if (delete_parent->left_child == delete_node) {
        delete_parent->left_child = NULL;
        free(delete_node);
      } else if (delete_parent->right_child == delete_node) {
        delete_parent->right_child = NULL;
        free(delete_node);
      }
  }

  return 0;
}

void destroy_tree(BST* bp) {
  if (bp == NULL) return;
  postorder_delete(bp->root);
  bp->node_cnt = 0;
}

void postorder_delete(node_t* np) {
if (np == NULL) return;

  postorder_delete(np->left_child);
  postorder_delete(np->right_child);
  free(np);
}

int main(void) {
  BST bst;
  init_tree(&bst);

  // add_node(&bst, 5);
  // add_node(&bst, 3);
  // add_node(&bst, 8);
  // add_node(&bst, 1);
  // add_node(&bst, 4);
  // add_node(&bst, 7);
  // add_node(&bst, 9);


  add_node(&bst, 7);
  add_node(&bst, 4);
  add_node(&bst, 11);
  add_node(&bst, 1);
  add_node(&bst, 5);
  add_node(&bst, 8);
  add_node(&bst, 15);
  add_node(&bst, 6);
  add_node(&bst, 13);
  add_node(&bst, 17);
  add_node(&bst, 12);
  add_node(&bst, 14);

  deleteNode(&bst, 15);


  printf("inorder traverse : ");
  inorder_traverse(bst.root);
  printf("\n");
  printf("preorder traverse : ");
  preorder_traverse(bst.root);
  printf("\n");
  printf("postorder traverse : ");
  postorder_traverse(bst.root);
  printf("\n");

  // deleteNode(&bst, 8);
  // postorder_traverse(bst.root);
  // printf("\n");

  destroy_tree(&bst);

  return 0;
}