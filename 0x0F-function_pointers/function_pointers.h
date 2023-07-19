#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/* Function that prints a name as is */
void print_name(char *name, void (*f)(char *));

/* Function that iterates over an array and performs an action on each element */
void array_iterator(int *array, size_t size, void (*action)(int));

#endif /* FUNCTION_POINTERS_H */
