#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H


/* Prints a name using the given printing function. */
void print_name(char *name, void (*f)(char *));
/* Executes a function on each element of an array. */
void array_iterator(int *array, size_t size, void (*action)(int));
/* Searches for an integer in an array. */
int int_index(int *array, int size, int (*cmp)(int));
#endif /* FUNCTION_POINTERS_H */
