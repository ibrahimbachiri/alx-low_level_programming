#include <unistd.h>
 
/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

