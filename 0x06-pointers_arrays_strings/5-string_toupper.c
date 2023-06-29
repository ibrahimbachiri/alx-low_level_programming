#include "main.h"
/**
 * string_toupper - Converts all lowercase letters of a string to uppercase.
 * @str: The string to be converted.
 *
 * Return: Pointer to the resulting string.
 */
char *string_toupper(char *str)
{
	int me;

	for (me = 0; str[me] != '\0'; me++)
	{
		if (str[me] >= 'a' && str[me] <= 'z')
		{
			str[me] = str[me] - 32;
		}
	}

	return str;
}
