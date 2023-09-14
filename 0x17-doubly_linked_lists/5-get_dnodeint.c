#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: A pointer to the head of the dlistint_t list.
 * @index: The index of the node to return, starting from 0.
 *
 * Return: If the node does not exist, return NULL. Otherwise, return the nth node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
	if (count == index)
	return (current);
	count++;
	current = current->next;
	}
	return (NULL); /* Node at the given index doesn't exist */
}
