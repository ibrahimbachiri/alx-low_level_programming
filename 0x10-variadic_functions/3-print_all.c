#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Print any combination of char, int, float, and string arguments.
 * @format: A list of types of arguments passed to the function.
 *          'c': A char argument.
 *          'i': An integer argument.
 *          'f': A float argument.
 *          's': A char pointer (string) argument. If the string is NULL,
 *               "(nil)" will be printed instead.
 *
 * Description: This variadic function takes a format string and a variable
 * number of arguments, allowing the user to print any combination of char,
 * int, float, and string values, similar to the printf function. The function
 * iterates over the format string, extracting and printing the corresponding
 * arguments based on the format specifiers. The arguments are separated by a
 * comma and space. The function ends with printing a new line character.
 *
 * Note: The function assumes that the caller provides appropriate format
 * specifiers and corresponding arguments, or it may lead to undefined behavior.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
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
				s_arg = va_arg(args, char*);
				printf("%s%s", separator, s_arg ? s_arg : "(nil)");
				break;
			default:
				break;
		}

		separator = ", ";
		i++;
	}

	va_end(args);
	printf("\n");
}
