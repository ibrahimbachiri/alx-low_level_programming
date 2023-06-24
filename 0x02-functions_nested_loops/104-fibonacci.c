k#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned long int num1 = 1;
    unsigned long int num2 = 2;
    unsigned long int nextNum;
    int count;

    printf("%lu, %lu, ", num1, num2); /* Print the first two Fibonacci numbers */

    for (count = 3; count <= 98; count++)
    {
        nextNum = num1 + num2;
        printf("%lu", nextNum);

        if (count < 98)
            printf(", ");

        num1 = num2;
        num2 = nextNum;
    }

    printf("\n");

    return (0);
}
