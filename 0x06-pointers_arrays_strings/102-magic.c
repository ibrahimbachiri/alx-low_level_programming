#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int a[5] = {98, 198, 298, 398, 498};
    int *p;
    
    p = &a[0];
    *(p + 2) = 98;
    printf("a[2] = %d\n", *(p + 2)); /* Your line of code */
    return 0;
}
