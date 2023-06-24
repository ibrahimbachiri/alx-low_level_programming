#include <stdio.h>

int main(void)
{
    unsigned long int num1 = 1;
    unsigned long int num2 = 2;
    unsigned long int nextNum;

    printf("%lu, %lu, ", num1, num2);

    while (num1 + num2 < 4000000)
    {
        nextNum = num1 + num2;
        printf("%lu, ", nextNum);

        num1 = num2;
        num2 = nextNum;
    }

    printf("\n");

    return 0;
}
