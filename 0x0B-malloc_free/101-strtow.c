#include <stdlib.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		else
		{
			while (str[i] == ' ')
				i++;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: An array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int word_count, word_len, i, j, k;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < word_count)
	{
		if (str[i] != ' ')
		{
			word_len = 0;
			k = i;
			while (str[k] != ' ' && str[k] != '\0')
			{
				word_len++;
				k++;
			}

			words[j] = (char *)malloc((word_len + 1) * sizeof(char));
			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			k = 0;
			while (str[i] != ' ' && str[i] != '\0')
			{
				words[j][k] = str[i];
				k++;
				i++;
			}
			words[j][k] = '\0';
			j++;
		}
		else
		{
			i++;
		}
	}

	words[j] = NULL;

	return (words);
}
