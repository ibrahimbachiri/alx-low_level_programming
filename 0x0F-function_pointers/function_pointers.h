#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/*
 * Description: This header file contains function prototypes for function_pointer.c.
 * - print_name: Takes a name and a function pointer as arguments and calls the function
 * pointed by the function pointer to print the name in a specific format.
 */
void print_name(char *name, void (*f)(char *));
/* Function prototype for print_name */
#endif /* FUNCTION_POINTERS_H */
