#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words
 */
int count_words(char *str)
{
    int i, count = 0, len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
            count++;
    }

    return count;
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int i, j, k, len = strlen(str);
    int word_count = count_words(str);

    char **words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    for (i = 0, j = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            int word_len = 0;
            for (k = i; k < len && str[k] != ' '; k++)
                word_len++;

            words[j] = malloc((word_len + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                for (j--; j >= 0; j--)
                    free(words[j]);
                free(words);
                return NULL;
            }

            strncpy(words[j], str + i, word_len);
            words[j][word_len] = '\0';
            i += word_len;
            j++;
        }
    }

    words[j] = NULL;
    return words;
}
