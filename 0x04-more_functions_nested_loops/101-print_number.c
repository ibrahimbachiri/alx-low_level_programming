#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
    if (n == 0)
    {
        _putchar('0');
        return;
    }

    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    int magnitude = 1;
    int temp = n;

    while (temp > 9)
    {
        magnitude *= 10;
        temp /= 10;
    }

    while (magnitude > 0)
    {
        int digit = n / magnitude;
        _putchar(digit + '0');
        n %= magnitude;
        magnitude /= 10;
    }
}
