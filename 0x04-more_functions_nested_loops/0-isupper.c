#include <unistd.h>

/**
 * _isupper - checks if a character is uppercase
 * @c: the character to be checked
 *
 * Description: Checks if the given character is an uppercase letter
 *              according to the ASCII values.
 *
 * Return: 1 if `c` is uppercase, 0 otherwise
 */

int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

