#ifndef HASHCHAINING_H_
#define HASHCHAINING_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
  int key;
  struct _node* next;
} node_t;

typedef struct _chaining_hash {
  node_t* hash;
  int size;
  int dataCnt;
} hash_t;

bool_t create_hash(hash_t* hsp, int size);
int hash_function(hash_t* hsp, int key);
bool_t hash_input(hash_t* hsp, int insert_data);
int hash_search(hash_t* hs, int search_data);
bool_t hash_delete(hash_t* hsp, int delete_data);
void destroy_hash(hash_t* hsp);
void hash_print(hash_t* hsp);


#endif