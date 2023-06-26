#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 11

int main(void)
{
    char password[PASSWORD_LENGTH];
    int i;

    srand(time(0));

    for (i = 0; i < PASSWORD_LENGTH - 1; i++)
    {
      
        password[i] = rand() % 36;
        if (password[i] < 26)
            password[i] += 'A';
        else
            password[i] += '0' - 26;
    }

    password[PASSWORD_LENGTH - 1] = '\0';

    printf("%s\n", password);

    return 0;
}
