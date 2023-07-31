#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Sum of all the data (n) of the linked list.
 *         If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
