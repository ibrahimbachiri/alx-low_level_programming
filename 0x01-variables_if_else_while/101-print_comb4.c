#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int digit1, digit2, digit3;

    for (digit1 = 0; digit1 <= 7; digit1++)
    {
        for (digit2 = digit1 + 1; digit2 <= 8; digit2++)
        {
            for (digit3 = digit2 + 1; digit3 <= 9; digit3++)
            {
                write(1, &digit1, 1);
                write(1, &digit2, 1);
                write(1, &digit3, 1);

                if (!(digit1 == 7 && digit2 == 8 && digit3 == 9))
                {
                    write(1, ", ", 2);
                }
            }
        }
    }

    write(1, "\n", 1);

    return (0);
}
