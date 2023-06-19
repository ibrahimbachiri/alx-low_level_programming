#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char letter;

	/* Print numbers 0-9 */
	for (num = 0; num <= 9; num++)
		putchar(num + '0');

	/* Print lowercase letters a-f */
	for (letter = 'a'; letter <= 'f'; letter++)
		putchar(letter);

	putchar('\n');

	return (0);
}
