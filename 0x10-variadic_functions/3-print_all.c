#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: A format string representing the types of arguments.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (if the string is NULL, print (nil) instead)
 *
 * Description: This function prints a variable number of arguments based on
 * the format string provided. It takes a constant pointer to a character,
 * representing the format string, and a variable number of arguments (denoted
 * by `...`). The function interprets the characters in the format string and
 * prints the corresponding argument based on the type specified. The supported
 * format characters are 'c' for char, 'i' for integer, 'f' for float, and 's'
 * for a string. If a string argument is NULL, the function prints "(nil)".
 * The printed arguments are separated by commas and spaces, and a newline
 * character is added at the end of the output.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *separator = "";

    va_start(args, format);

    while (format && format[i])
    {
        switch (format[i])
        {
            case 'c':
                print_char(args, separator);
                break;
            case 'i':
                print_int(args, separator);
                break;
            case 'f':
                print_float(args, separator);
                break;
            case 's':
                print_string(args, separator);
                break;
            default:
                break;
        }

        separator = ", ";
        i++;
    }

    printf("\n");
    va_end(args);
}

/* Helper functions for printing each argument type */

void print_char(va_list args, char *separator)
{
    char c_arg = va_arg(args, int);
    printf("%s%c", separator, c_arg);
}

void print_int(va_list args, char *separator)
{
    int i_arg = va_arg(args, int);
    printf("%s%d", separator, i_arg);
}

void print_float(va_list args, char *separator)
{
    float f_arg = va_arg(args, double);
    printf("%s%f", separator, f_arg);
}

void print_string(va_list args, char *separator)
{
    char *s_arg = va_arg(args, char *);
    if (s_arg == NULL)
        s_arg = "(nil)";
    printf("%s%s", separator, s_arg);
}
