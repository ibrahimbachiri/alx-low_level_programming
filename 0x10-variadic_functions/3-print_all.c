#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: The format string representing the types of arguments.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (if the string is NULL, print (nil) instead)
 *          Any other char should be ignored.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";
	char *s_arg;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", separator, va_arg(args, int));
		}
		else if (format[i] == 'i')
		{
			printf("%s%d", separator, va_arg(args, int));
		}
		else if (format[i] == 'f')
		{
			printf("%s%f", separator, va_arg(args, double));
		}
		else if (format[i] == 's')
		{
			s_arg = va_arg(args, char *);
			if (s_arg == NULL)
				s_arg = "(nil)";
			printf("%s%s", separator, s_arg);
		}

		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
