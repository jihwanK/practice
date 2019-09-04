#include <stdio.h>
#include "HashChaining.h"

bool_t create_hash(hash_t* hsp, int size) {
  hsp->hash = (node_t*) malloc(sizeof(node_t) * size);
  hsp->size = size;
  hsp->dataCnt = 0;
}

int hash_function(hash_t* hsp, int key) {
  int key_sum = 0;

  if (hsp == NULL) return FALSE;

  while (key > 0) {
    key_sum += key % 10;
    key /= 10;
  }

  printf("key_sum = %d \n", key_sum);
  return key_sum % hsp->size;
}

bool_t hash_input(hash_t* hsp, int insert_data) {
  if (hsp == NULL) return FALSE;

  int init_hash_value = hash_function(hsp, insert_data);
  int hash_value; = init_hash_value;

  node_t* cur = hsp->hash[hash_value];
  
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->key = insert_data;
  new_node->next = NULL;

  while (cur.next != NULL) {
    cur = cur->next;
  }
  cur->next = new_node;

  return TRUE;
}

int hash_search(hash_t* hs, int search_data) {
  int init_hash_value = hash_function(hsp, search_data);
  int hash_value; = init_hash_value;
  node_t* cur = hsp->hash[hash_value];

  while (cur.key != search_data) {
    cur = cur->next;
  }

}

bool_t hash_delete(hash_t* hsp, int delete_data) {

}

void destroy_hash(hash_t* hsp) {

}

void hash_print(hash_t* hsp) {

}
