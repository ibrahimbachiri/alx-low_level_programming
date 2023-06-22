#include "main.h"
#include <unistd.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = '0';
    putchar("%c: %d\n", c, _isdigit(c));
    c = 'a';
    putchar("%c: %d\n", c, _isdigit(c));
    return (0);
}
