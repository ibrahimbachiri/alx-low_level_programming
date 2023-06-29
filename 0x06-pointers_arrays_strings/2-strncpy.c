#include "main.h"
/**
 * _strncpy - Copies at most n bytes of the src string to dest.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of bytes to be copied from src.
 *
 * Return: Pointer to the resulting string 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int why;

	for (why = 0; why < n && src[why] != '\0'; why++)
		dest[why] = src[why];

	for (; why < n; why++)
		dest[why] = '\0';

	return dest;
}
