#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i;
	int len, total_len = 0;
	int current_index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			len++;
			total_len++;
		}
		total_len++;
	}

	str = malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			str[current_index] = av[i][len];
			current_index++;
			len++;
		}
		str[current_index] = '\n';
		current_index++;
	}
	str[current_index] = '\0';

	return (str);
}
