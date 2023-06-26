#include "main.h"

int _putchar(char c);

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: The string to be printed.
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	i--;

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
