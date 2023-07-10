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
 * allocate_words - Allocates memory for the words array.
 * @word_count: The number of words.
 *
 * Return: The allocated words array.
 */
char **allocate_words(int word_count)
{
	char **words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * allocate_word - Allocates memory for a single word.
 * @word_len: The length of the word.
 *
 * Return: The allocated word.
 */
char *allocate_word(int word_len)
{
	char *word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	return (word);
}

/**
 * copy_word - Copies a word from the input string to the word array.
 * @word: The word array.
 * @str: The input string.
 * @start: The starting index of the word in the input string.
 * @end: The ending index of the word in the input string.
 */
void copy_word(char *word, char *str, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
		word[i - start] = str[i];

	word[i - start] = '\0';
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

	words = allocate_words(word_count);
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

			words[j] = allocate_word(word_len);
			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			copy_word(words[j], str, i, k);
			j++;
		}
		i++;
	}

	words[j] = NULL;

	return (words);
}
