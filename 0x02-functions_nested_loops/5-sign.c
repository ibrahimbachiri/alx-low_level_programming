#include "main.h"

/**
 * print_sign - Prints the sign of a number
 * @n: The number to check
 *
 * Return: '+' if n is greater than zero, '0' if n is zero, '-' if n is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
		return ('+');
	else if (n == 0)
		return ('0');
	else
		return ('-');
}

