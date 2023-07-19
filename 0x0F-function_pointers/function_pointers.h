#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H
void print_name(char *name, void (*f)(char *));
/*                                                                                                                                                   * array_iterator - Executes a function on each element of an array.                                                                                 * @array: Pointer to the array of integers.                                                                                                         * @size: The size of the array.                                                                                                                     * @action: Pointer to the function to be executed on each array element.                                                                            */
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
#endif /* FUNCTION_POINTERS_H */
