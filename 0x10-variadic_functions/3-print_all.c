#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format provided
 * @format: A list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 * Any other char should be ignored
 */
void print_all(const char * const format, ...)
{
    va_list args;
    char *str;
    int int_arg;
    float float_arg;
    char char_arg;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        char_arg = format[i];

        if (format[i + 1])
        {
            i++;
        }

        switch (char_arg)
        {
        case 'c':
            printf("%c", va_arg(args, int));
            break;
        case 'i':
            int_arg = va_arg(args, int);
            printf("%d", int_arg);
            break;
        case 'f':
            float_arg = va_arg(args, double);
            printf("%f", float_arg);
            break;
        case 's':
            str = va_arg(args, char*);
            if (str == NULL)
            {
                str = "(nil)";
            }
            printf("%s", str);
            break;
        }
        if (format[i + 1])
        {
            printf(", ");
        }
        i++;
    }

    va_end(args);

    printf("\n");
}
