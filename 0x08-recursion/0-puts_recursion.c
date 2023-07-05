#include <string.h>
#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line.
 * @s: The string to be printed.
 */
void _puts_recursion(char *s)
{
    if (strlen(s) == 0)
    {
        _putchar('\n');
        return;
    }

    _putchar(s[0]);
    _puts_recursion(s + 1);
}
