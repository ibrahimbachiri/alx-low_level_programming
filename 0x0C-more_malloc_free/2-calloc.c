#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array and initializes it with zero
 * @nmemb: The number of elements in the array
 * @size: The size (in bytes) of each element
 *
 * Return: A pointer to the allocated memory
 *         If nmemb or size is 0, returns NULL
 *         If malloc fails, returns NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size = nmemb * size;
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	memset(ptr, 0, total_size);

	return (ptr);
}
