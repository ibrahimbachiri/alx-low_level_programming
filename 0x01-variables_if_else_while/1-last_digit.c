#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is ", n);

	if (n < 0)
		n = -n; /* Get the absolute value of n */

	while (n >= 10)
		n /= 10; /* Keep dividing by 10 until the last digit is reached */

	printf("%d and is ", n);

	if (n > 5)
		printf("greater than 5\n");
	else if (n == 0)
		printf("0\n");
	else
		printf("less than 6 and not 0\n");

	return (0);
}
