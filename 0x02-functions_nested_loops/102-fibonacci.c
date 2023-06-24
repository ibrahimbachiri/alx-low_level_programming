#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    int i;
    long int fib1 = 1; 
    long int fib2 = 2;     
    printf("%ld, %ld", fib1, fib2);
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
