#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * @cmp: Pointer to the function to be used for comparison.
 *
 * Return: Index of the first element for which cmp does not return 0.
 *         -1 if no element matches the condition or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp)
	{
		size_t i;
		for (i = 0; i < (size_t)size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
