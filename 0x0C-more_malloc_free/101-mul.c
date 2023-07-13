#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Computes the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _multiply - Multiplies two positive numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 *
 * Return: A pointer to the result as a string
 */
char *_multiply(char *num1, char *num2)
{
	unsigned int len1 = _strlen(num1);
	unsigned int len2 = _strlen(num2);
	unsigned int result_len = len1 + len2;
	unsigned int i, j, carry, digit;
	int *result;
	char *mul;

	result = calloc(result_len, sizeof(int));
	if (result == NULL)
		return (NULL);

	for (i = len1 - 1; i < len1; i--)
	{
		carry = 0;
		for (j = len2 - 1; j < len2; j--)
		{
			digit = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			result[i + j + 1] = digit % 10;
			carry = digit / 10;
		}
		result[i] += carry;
	}

	mul = malloc(sizeof(char) * (result_len + 1));
	if (mul == NULL)
	{
		free(result);
		return (NULL);
	}

	for (i = 0; i < result_len; i++)
		mul[i] = result[i] + '0';

	mul[result_len] = '\0';

	free(result);

	return (mul);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, 1 otherwise
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = argv[1];
	num2 = argv[2];

	while (*num1 != '\0')
	{
		if (!_isdigit(*num1))
		{
			printf("Error\n");
			return (1);
		}
		num1++;
	}

	while (*num2 != '\0')
	{
		if (!_isdigit(*num2))
		{
			printf("Error\n");
			return (1);
		}
		num2++;
	}

	result = _multiply(argv[1], argv[2]);
	if (result == NULL)
	{
		printf("Error\n");
		return (1);
	}

	printf("%s\n", result);
	free(result);

	return (0);
}
