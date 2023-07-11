#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_tab - Frees the memory allocated for a table of strings.
 * @tab: The table of strings to free.
 *
 * Return: Nothing.
 */
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

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int len = strlen(str);
	int i, j, k = 0, word_count = 0;
	char **s;

	if (len == 0)
	  return (NULL);

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			word_count++;
	}

	s = (char **)malloc((word_count + 1) * sizeof(char *));
	if (s == NULL)
	  return (NULL);

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			int word_len = 0;
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
			{
				word_len++;
				j++;
			}

			s[k] = (char *)malloc((word_len + 1) * sizeof(char));
			if (s[k] == NULL)
			{
				free_tab(s);
				return (NULL);
			}

			strncpy(s[k], str + i, word_len);
			s[k][word_len] = '\0';
			k++;
		}
	}

	s[k] = NULL;

	return (s);
}
