#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int j[5];
    int *k;

    j[2] = 1024;
    k = &j[2] - 2;

    /* Add your code here */
    printf("j[2] = 98\n");

    return (0);
}
