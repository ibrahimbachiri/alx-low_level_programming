#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of bytes to be used from src.
 *
 * Return: Pointer to the resulting string 'dest'.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_lenght = 0;
	int i;

	
	while (dest[dest_lenght] != '\0')
		dest_lenght++;

	
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_lenght++] = src[i];

	dest[dest_lenght] = '\0';

	return dest;
}
