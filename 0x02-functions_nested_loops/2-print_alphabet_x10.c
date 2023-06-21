#include "main.h"
#include "stdio.h"

/**
 * print_alphabet_x10 - Prints the alphabet 10 times in lowercase
 */
void print_alphabet_x10(void)
{
	char r;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (r = 'a'; r <= 'z'; r++)
		{
			putchar(r);
		}
		putchar('\n');
	}
}
