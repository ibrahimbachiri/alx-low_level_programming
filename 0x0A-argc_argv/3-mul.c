#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 (Success) or 1 (Error)
 */
int main(int argc, char *argv[])
{
    int one, two, addition;

    if (argc != 3)
    {
        printf("Error\n");
        return 1;
    }

    one = atoi(argv[1]);
    two = atoi(argv[2]);
    addition = one * two;

    printf("%d\n", addition);

    return 0;
}
