#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet 10 times in lowercase
 */
void print_alphabet_x10(void)
{
    char r;
    int i;

    for (i = 0; i < 10; i++) // Loop for printing the alphabet 10 times
    {
        for (r = 'a'; r <= 'z'; r++) // Loop for printing each character of the alphabet
        {
            _putchar(r);
        }
        _putchar('\n');
    }
}
