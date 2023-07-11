#include "main.h"
#include <stdlib.h>
#include <string.h>

char **strtow(char *str)
{
    int len = 0, l = 0, i, j = 0;
    char **s;

    if (str == NULL)
        return NULL;

    for (len = 0; str[len] != '\0'; len++)
        ;

    s = (char **)malloc((len + 1) * sizeof(char *));
    if (s == NULL)
        return NULL;

    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ' && l == 0)
        {
            s[j] = malloc((i - l + 1) * sizeof(char));
            strncpy(s[j], str + l, i - l);
            s[j][i - l] = '\0';
            j++;
            l = i + 1;
        }
        else if (str[i] != ' ')
        {
            if (l == 1)
            {
                l = i;
            }
            else if (l == 0 && (i == 0 || str[i - 1] == ' '))
            {
                l = i;
            }
        }
    }

    if (l < len)
    {
        s[j] = malloc((len - l + 1) * sizeof(char));
        strncpy(s[j], str + l, len - l);
        s[j][len - l] = '\0';
        j++;
    }

    s[j] = NULL;

    return s;
}

void free_tab(char **tab)
{
    int i;

    if (tab == NULL)
        return;

    for (i = 0; tab[i] != NULL; i++)
    {
        free(tab[i]);
    }
    free(tab);
}
