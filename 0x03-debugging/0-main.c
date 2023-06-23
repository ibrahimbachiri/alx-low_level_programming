#include <stdio.h>

/**
 * positive_or_negative - Prints if a number is positive or negative
 * @i: The number to be checked
 */
void positive_or_negative(int i)
{
    if (i > 0)
        printf("%d is positive\n", i);
    else if (i < 0)
        printf("%d is negative\n", i);
    else
        printf("%d is zero\n", i);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;

    i = 98;
    positive_or_negative(i);

    return (0);
}

