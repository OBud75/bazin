typedef struct Person{
  int age;
} Person;

typedef struct Book{
  int pages;
} Book;

int are_persons_equals(Person *p1, Person *p2);
int are_books_equals(Book *p1, Book *p2);
int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void*, void*));

int is_in_array(
    void *obj_to_find,
    void *array[],
    int nb_element, // in the array
    int elem_size,
    int (*compare_fnc)(void*, void*)
    );
