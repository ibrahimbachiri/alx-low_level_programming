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
	char c_arg;
	int i_arg;
	float f_arg;
	char *s_arg;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			c_arg = va_arg(args, int);
			printf("%s%c", separator, c_arg);
			break;
		case 'i':
			i_arg = va_arg(args, int);
			printf("%s%d", separator, i_arg);
			break;
		case 'f':
			f_arg = va_arg(args, double);
			printf("%s%f", separator, f_arg);
			break;
		case 's':
			s_arg = va_arg(args, char *);
			if (s_arg == NULL)
				s_arg = "(nil)";
			printf("%s%s", separator, s_arg);
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
