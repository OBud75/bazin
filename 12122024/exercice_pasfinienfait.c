#include "exercices.h"
#include <stdio.h>

typedef struct Person {
  int age;
} Person;
typedef struct Book {
  int pages;
} Book;

int are_persons_equals(Person *p1, Person *p2) {
  return p1->age == p2->age;
}

int are_books_equals(Book *b1, Book *b2) {
  return b1->pages == b2->pages;
}

int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void *, void *)) {
  return compare_fnc(obj1, obj2);
}

int is_in_array(void *obj_to_find,
                void *array[],
                int nb_of_elems_in_array,
                size_t elem_size,
                int (*compare_fnc)(void *, void *)) {
  for (int i = 0; i < nb_of_elems_in_array; i++) {
    if (compare_fnc(obj_to_find, (char*)array + i * elem_size)) {
      return 1;
    }
  }
  return 0;
}

int main () {
  Person person1 = {50};
  Person person2 = {50};
  int same_age = are_equals(
    &person1,
    &person2,
    (int (*)(void *, void *)) are_persons_equals
  );
  if (same_age == 1) {
    printf("Same age.\n");
  } else {
    printf("Not same age.\n");
  }

  Person people[] = {{20}, {50}};
  int found = is_in_array(
    &person1,
    (void *)people,
    2,
    sizeof(Person),
    (int (*)(void *, void *)) are_persons_equals
  );
  if (found == 1) {
    printf("Person found in array.\n");
  } else {
    printf("Person not found in array.\n");
  }

  return 0;
}
