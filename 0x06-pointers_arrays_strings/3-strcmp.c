#include "main.h"
/**
 * _strcmp - Compares two strings.
 * @s4: Pointer to the first string.
 * @s0: Pointer to the second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s4, char *s0)
{
	while (*s4 && (*s4 == *s0))
	{
		s4++;
		s0++;
	}

	return (*s4 - *s0);
}
