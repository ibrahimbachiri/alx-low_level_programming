#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/*
 * Description: This header file contains function prototypes for function_pointer.c.
 * It declares three functions:
 *   - print_name: Takes a name and a function pointer as arguments and calls the function
 *                 pointed by the function pointer to print the name in a specific format.
 *   - print_name_as_is: Prints a given name as it is without any modifications.
 *   - print_name_uppercase: Prints a given name in uppercase letters.
 */

/* Function prototype for print_name */
void print_name(char *name, void (*f)(char *));





#endif /* FUNCTION_POINTERS_H */
