#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - Deletes a node at a given index in a doubly linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to delete, starting from 0.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (!*head)
	return (-1);

	if (index == 0)
	{
	*head = (*head)->next;
	if (*head)
	(*head)->prev = NULL;
	free(current);
	return (1);
	}

	while (current && i < index)
	{
	current = current->next;
	i++;
	}

	if (!current)
	return (-1);

	if (current->next)
        current->next->prev = current->prev;
	if (current->prev)
	current->prev->next = current->next;

	free(current);
	return (1);
}
