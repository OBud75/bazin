#include "exercice.h"
#include <stdio.h>

typedef struct Person {
  int age;
} Person;
typedef struct Book {
  int pages;
} Book;

int are_persons_equals(Person *p1, Person *p2) {
  //return 1 if same age
};
int are_books_equals(Book *b1, Book *b2) {
  //return 1 if same nb of pages
};
int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void *, void *)) {

};
int is_in_array(void *obj_to_find,
                void *array[]
                int nb_of_elems_in_array,
                size_t elem_size,
                int (*compare_fnc)(void *, void *) {
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
  };
  Person people[] = {{20}, {10}};
  int is_in_array(
    &person1,
    &people,
    2,
    sizeof(Person)
    (int (*)(void *, void *)) are_persons_equals
  );
  if (same_age == 1) {
    printf("Same age.\n");
  };
}
