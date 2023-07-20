#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

/**
 * struct format - Struct to store a format specifier and its corresponding function
 * @spec: The format specifier
 * @func: The corresponding function to handle the format specifier
 */
typedef struct format
{
	char *spec;
	void (*func)(va_list);
} format_t;

int sum_them_all(const unsigned int n, ...);
#endif /* VARIADIC_FUNCTIONS_H */
