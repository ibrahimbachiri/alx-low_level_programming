#include <unistd.h>
 
/**
 * _isdigit - Checks if a character is uppercase
 * @c: The character to be checked
 *
 * Description: Checks if the given character is an uppercase letter
 * according to the ASCII value.
 *
 * Return: 1 if c is a uppercase, 0 otherwise
 */

int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}
