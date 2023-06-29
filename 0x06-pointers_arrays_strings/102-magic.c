#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int a[5];
    int *p;

    a[2] = 1024;
    p = &a[2] - 2;

    /* Add your code here */
    printf("a[2] = 98\n");

    return (0);
}
