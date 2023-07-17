#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Description: This function is the starting point of the program. It prints
 *              the name of the file it was compiled from, followed by a new line.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
    printf("%s\n", __FILE__);
    return 0;
}
