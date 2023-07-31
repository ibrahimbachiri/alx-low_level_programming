#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data (n) stored in the deleted head node.
 *         If the linked list is empty, return 0.
 */
int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (data);

	data = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (data);
}
