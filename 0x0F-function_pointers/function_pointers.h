#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H


/* Function that prints a name as is */
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
#endif /* FUNCTION_POINTERS_H */
