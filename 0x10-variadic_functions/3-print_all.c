#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: Format string representing the types of arguments.
 *           c: char
 *           i: integer
 *           f: float
 *           s: char * (if the string is NULL, print (nil) instead)
 *           Any other char should be ignored.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";
	char c_arg;
	int i_arg;
	float f_arg;
	char *s_arg;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			c_arg = va_arg(args, int);
			printf("%s%c", separator, c_arg);
		}
		else if (format[i] == 'i')
		{
			i_arg = va_arg(args, int);
			printf("%s%d", separator, i_arg);
		}
		else if (format[i] == 'f')
		{
		  f_arg = va_arg(args, double);
			printf("%s%f", separator, f_arg);
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
