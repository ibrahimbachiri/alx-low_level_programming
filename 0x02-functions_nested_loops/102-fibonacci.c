#include <unistd.h>

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
    char comma[] = ", ";
    char newline[] = "\n";

    /* Print the first two Fibonacci numbers */
    write(STDOUT_FILENO, &fib1, sizeof(fib1));
    write(STDOUT_FILENO, comma, sizeof(comma) - 1);
    write(STDOUT_FILENO, &fib2, sizeof(fib2));

    /* Generate and print the remaining Fibonacci numbers */
    for (i = 3; i <= 50; i++)
    {
        long int nextFib = fib1 + fib2;
        write(STDOUT_FILENO, comma, sizeof(comma) - 1);
        write(STDOUT_FILENO, &nextFib, sizeof(nextFib));
        fib1 = fib2;
        fib2 = nextFib;
    }

    write(STDOUT_FILENO, newline, sizeof(newline) - 1);

    return (0);
}
