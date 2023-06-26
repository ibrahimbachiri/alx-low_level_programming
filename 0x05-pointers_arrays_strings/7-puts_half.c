#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 *
 * Return: On success, the character written is returned.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);

/**
 * puts_half - Prints half of a string, followed by a new line.
 * @str: The string to be printed.
 */
void puts_half(char *str)
{
	int length = 0;
	int i, n;

	while (str[length] != '\0')
		length++;

	n = (length - 1) / 2;

	for (i = n + 1; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}
