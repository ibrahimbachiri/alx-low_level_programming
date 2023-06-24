#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	long int fib1 = 1; /* First Fibonacci number */
	long int fib2 = 2; /* Second Fibonacci number */

	/* Print the first two Fibonacci numbers */
	printf("%ld, %ld", fib1, fib2);

	/* Generate and print the remaining Fibonacci numbers */
	for (i = 3; i <= 50; i++)
	{
		long int nextFib = fib1 + fib2;
		printf(", %ld", nextFib);
		fib1 = fib2;
		fib2 = nextFib;
	}

	printf("\n");

	return (0);
}
