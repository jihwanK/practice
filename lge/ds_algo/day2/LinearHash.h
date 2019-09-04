#ifndef LINEARHASH_H_
#define LINEARHASH_H_

#define EMPTY -1
#define DELETE -2
typedef enum { FALSE, TRUE } bool_t;

typedef struct _linear_hash {
  int* hash;
  int size;
} Hash;

bool_t create_hash(Hash* hsp, int size);
int hash_function(Hash* hsp, int key);
bool_t hash_input(Hash* hsp, int insert_data);
int hash_search(Hash* hsp, int search_data);
bool_t hash_delete(Hash* hsp, int delete_data);
void destroy_hash(Hash* hsp);
void hash_print(const Hash* hsp);

#endif