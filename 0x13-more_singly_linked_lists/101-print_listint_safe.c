#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_node - Print a single node.
 * @node: The node to print.
 */
void print_node(const listint_t *node)
{
    printf("[%p] %d\n", (void *)node, node->n);
}

/**
 * check_for_loop - Check if there is a loop in the linked list.
 * @head: Pointer to the head node of the linked list.
 * @nodes: Array of pointers to store visited nodes.
 * @count: Pointer to the variable storing the number of nodes visited.
 *
 * Return: 1 if a loop is detected, 0 otherwise.
 */
int check_for_loop(const listint_t *head, const listint_t **nodes, size_t *count)
{
	size_t i;
	const listint_t *current = head;

	while (current != NULL)
	{
		for (i = 0; i < *count; i++)
		{
			if (current == nodes[i])
			{
				/* Loop detected */
				return (1);
			}
		}

		/* Add the current node to the array of visited nodes */
		nodes[*count] = current;
		(*count)++;

		/* Move to the next node */
		current = current->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	int is_loop = 0;
	const listint_t *current = head;
	const listint_t *nodes[1024]; /* Assuming a maximum of 1024 nodes */

	is_loop = check_for_loop(head, nodes, &count);

	while (current != NULL)
	{
		if (is_loop && current == nodes[count - 1])
		{
			/* Print the node where the loop starts using the '->' notation */
			printf("[%p] %d\n", (void *)current, current->n);
			break;
		}

		/* Print the current node */
		print_node(current);

		/* Move to the next node */
		current = current->next;
	}

	if (is_loop)
	{
		/* Exit with status 98 if a loop is detected */
		exit(98);
	}

	return (count);
}
