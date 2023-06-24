#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int num1, num2;

    for (num1 = 0; num1 <= 98; num1++)
    {
        for (num2 = num1 + 1; num2 <= 99; num2++)
        {
            write(1, (num1 / 10) + '0', 1);
            write(1, (num1 % 10) + '0', 1);
            write(1, " ", 1);
            write(1, (num2 / 10) + '0', 1);
            write(1, (num2 % 10) + '0', 1);

            if (!(num1 == 98 && num2 == 99))
            {
                write(1, ", ", 2);
            }
        }
    }

    write(1, "\n", 1);

    return (0);
}
