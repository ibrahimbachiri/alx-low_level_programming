#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory block
 * @old_size: Size of the allocated space for ptr, in bytes
 * @new_size: New size of the memory block, in bytes
 *
 * Return: Pointer to the reallocated memory block
 *         If new_size == old_size, returns ptr
 *         If new_size is 0 and ptr is not NULL, frees ptr and returns NULL
 *         If malloc fails, returns NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);

		if (new_size < old_size)
			old_size = new_size;

		memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}

	return (new_ptr);
}
