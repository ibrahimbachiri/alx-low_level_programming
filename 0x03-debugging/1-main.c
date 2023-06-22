#include <stdio.h>

/**
 * main - Causes an infinite loop
 *
 * Return: Always 0
 */
int main(void)
{
        int i;

        printf("Infinite loop incoming :(\n");

        i = 0;

        /* Commented out the code causing the infinite loop
         * while (i < 10)
         * {
         *        putchar(i);
         * }
         */

        printf("Infinite loop avoided! \\o/\n");

        return (0);
}

