#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 *
 * Return: On success, returns the character written as an unsigned char cast
 * to an int. On error, returns -1.
 */
int _putchar(char c);

/**
 * _puts - Prints a string followed by a new line
 * @str: Pointer to the string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
