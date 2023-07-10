#include <stdlib.h>
#include <string.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0;
	char *concatenated;
	unsigned int i, j;

	if (s1 != NULL)
		len1 = strlen(s1);
	if (s2 != NULL)
		len2 = strlen(s2);

	concatenated = malloc((len1 + len2 + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	for (j = 0; j < len2; j++)
		concatenated[i++] = s2[j];

	concatenated[i] = '\0';

	return (concatenated);
}
