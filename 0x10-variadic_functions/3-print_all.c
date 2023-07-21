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
	int i = 0, j = 0;
	char *separator = "";

	va_start(args, format);

	valid_format formats[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	while (format && format[i])
	{
		j = 0;
		while (formats[j].specifier != 0)
		{
			if (format[i] == formats[j].specifier)
			{
				printf("%s", separator);
				formats[j].print_func(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	va_end(args);

	printf("\n");
}
