#include <unistd.h>


/**
 * _isupper - checks if a character is uppercase
 * @c: the character to be checked
 *
 */

int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

