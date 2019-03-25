#include <stdio.h>
#include "LinearHash.h"



bool_t create_hash(Hash* hsp, int size) {

}

bool_t hash_input(Hash* hsp, int insert_data) {

}

int hash_search(Hash* hsp, int search_data) {

}

bool_t hash_delete(Hash* hsp, int delete_data) {

}

void destroy_hash(Hash* hsp) {

}

void hash_print(const Hash* hsp) {

}


int hash_function(Hash* hsp, int key) {
  int key_sum = 0;

  if (hsp == NULL) return FALSE;

  while (key > 0) {
    key_sum += key % 10;
    key /= 10;
  }

  printf("key_sum = %d \n", key_sum);
  return key_sum % 10;
}