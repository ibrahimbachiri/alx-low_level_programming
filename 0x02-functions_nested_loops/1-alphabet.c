#include <stdio.h>

/**
 * print_alphabet - Prints the alphabet in lowercase.
 */
void print_alphabet(void)
{
    char letter;

    for (letter = 'a'; letter <= 'z'; letter++)
    {
        putchar(letter);
    }

    putchar('\n');
}

int main(void)
{
    print_alphabet();
    return 0;
}
