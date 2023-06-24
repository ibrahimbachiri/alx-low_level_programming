#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    long int fib1 = 1; /* First Fibonacci number */
    long int fib2 = 2; /* Second Fibonacci number */
    long int nextFib;
    long int sum = 2; /* Initial sum with the second Fibonacci number */

    /* Generate the Fibonacci sequence and calculate the sum of even-valued terms */
    while (fib2 <= 4000000)
    {
        nextFib = fib1 + fib2;

        if (nextFib % 2 == 0)
            sum += nextFib;

        fib1 = fib2;
        fib2 = nextFib;
    }

    printf("%ld\n", sum);

    return 0;
}
