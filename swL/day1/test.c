#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person {
  char* name;
  int age;
} person_t;

int main(void) {
  char name[1024];
  int age;

  printf("input name: ");
  scanf("%s", name);
  printf("input age: ");;
  scanf("%d", &age);

  person_t p1;
  person_t p2;

  p1.name = (char*) malloc(sizeof(char) * strlen(name) + 1);
  strcpy(p1.name, name);
  p1.age = age;
  printf("%s (%d) \n", p1.name, p1.age);

  p2.name = (char*) malloc(sizeof(char*) * strlen(p1.name) + 1);
  strcpy(p2.name, p1.name);
  p2.age = p1.age;
  printf("%s (%d) \n", p2.name, p2.age);

  free(p1.name);
  free(p2.name);

  return 0;
}