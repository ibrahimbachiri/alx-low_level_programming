#include <stdio.h>
#include <stdlib.h>

/*
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    int i, num_bytes;

    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    num_bytes = atoi(argv[1]);

    if (num_bytes < 0)
    {
        printf("Error\n");
        exit(2);
    }

    unsigned char *main_ptr = (unsigned char *)&main;

    for (i = 0; i < num_bytes; i++)
    {
        printf("%02x", main_ptr[i]);
        if (i < num_bytes - 1)
            printf(" ");
    }
    printf("\n");
    return (0);
}
