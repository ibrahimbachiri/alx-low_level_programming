#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of arguments to be passed to the function.
 *
 * Return: The sum of all the parameters.
 *         If n == 0, return 0.
 */
int sum_them_all(const unsigned int n, ...)
{
        va_list args;                 /* Declare a variable to hold the arguments */
        int sum = 0;                  /* Initialize the sum to 0 */
        unsigned int i;               /* Declare a counter variable */

        if (n == 0)
                return (0);           /* If there are no arguments, return 0 */

        va_start(args, n);            /* Start processing the variadic arguments */

        for (i = 0; i < n; i++)
                sum += va_arg(args, int);  /* Add each argument to the sum */

        va_end(args);                 /* End processing the variadic arguments */

        return (sum);                 /* Return the final sum */
}
