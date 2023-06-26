#include "main.h"
#include <stdio.h>

/**
 * print_rev - Prints a string in reverse
 * @s: Pointer to the string
 */
int _putchar(char c);

void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	while (i >= 0)
	{
		putchar(s[i]);
		i--;
	}
	putchar('\n');
}










       
