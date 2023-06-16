#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase,
 * excluding the letters 'q' and 'e', followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		if (lowercase != 'q' && lowercase != 'e')
			putchar(lowercase);
	}

	putchar('\n');

	return (0);
}
