#include <stdio.h>
#include <stdlib.h>

/**
 * get_min_coins - Calculates the minimum number of coins required
 *                 to make change for the given amount of money.
 * @cents: The amount of money in cents.
 *
 * Return: The minimum number of coins required.
 */
int get_min_coins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = sizeof(coins) / sizeof(coins[0]);
	int count = 0;
	int i;

	if (cents < 0)
		return 0;

	for (i = 0; i < num_coins; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			count++;
		}
	}

	return count;
}

/**
 * main - Entry point. Calculates the minimum number of coins required
 *        to make change for the given amount of money.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	int cents;
	int min_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return 1;
	}

	cents = atoi(argv[1]);
	min_coins = get_min_coins(cents);

	printf("%d\n", min_coins);

	return 0;
}
