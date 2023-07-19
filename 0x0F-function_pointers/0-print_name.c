#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name using the given printing function.
 * @name: Pointer to the name to be printed.
 * @f: Pointer to the printing function.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *)) {
    f(name);
}
