#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int digit1, digit2;

    for (digit1 = 0; digit1 <= 8; digit1++)
    {
        for (digit2 = digit1 + 1; digit2 <= 9; digit2++)
        {
            write(1, &digit1, 1);
            write(1, &digit2, 1);

            if (digit1 != 8 || digit2 != 9)
            {
                write(1, ", ", 2);
            }
        }
    }

    write(1, "\n", 1);

    return (0);
}
