#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned int count;
    unsigned int num1 = 1;
    unsigned int num2 = 2;
    unsigned int nextNum;

    printf("%u, %u", num1, num2); /* Print the first two Fibonacci numbers */

    for (count = 3; count <= 98; count++)
    {
        nextNum = num1 + num2;
        printf(", %u", nextNum);

        num1 = num2;
        num2 = nextNum;
    }

    printf("\n");

    return 0;
}
