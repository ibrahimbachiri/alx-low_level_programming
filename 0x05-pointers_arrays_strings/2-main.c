#include "main.h"
#include <stdio.h>

int main(void)
{
    char *str = "I am twelve years old";
    int len = _strlen(str);
    printf("%d\n", len);  // Output: 23

    return 0;
}
