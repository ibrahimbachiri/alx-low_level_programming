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
 * prints the corresponding argument based on the type specified.
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
