#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - Prints a char argument
 * @args: va_list containing the arguments
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an int argument
 * @args: va_list containing the arguments
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float argument
 * @args: va_list containing the arguments
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string argument
 * @args: va_list containing the arguments
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

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
