#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct format - Struct to store a format specifier and its corresponding function
 * @spec: The format specifier
 * @func: The corresponding function to handle the format specifier
 */
struct format
{
	char *spec;
	void (*func)(va_list args);
};
typedef struct format format_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
