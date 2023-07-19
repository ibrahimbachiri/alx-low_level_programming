#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * struct dog - A simple structure for a dog's information.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: Basic information about a dog, including its name, age, and owner.
 */

/**
 * print_name - Prints a name using the given printing function.
 * @name: Pointer to the name to be printed.
 * @f: Pointer to the printing function.
 */
void print_name(char *name, void (*f)(char *));

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: Pointer to the array of integers.
 * @size: The size of the array.
 * @action: Pointer to the function to be executed on each array element.
 */
void array_iterator(int *array, size_t size, void (*action)(int));

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the array of integers.
 * @size: The size of the array.
 * @cmp: Pointer to the function used to compare values.
 *
 * Return: Index of the first element for which the cmp function does not return 0,
 *         or -1 if no element matches or size is less than or equal to 0.
 */
int int_index(int *array, int size, int (*cmp)(int));

#endif /* FUNCTION_POINTERS_H */
