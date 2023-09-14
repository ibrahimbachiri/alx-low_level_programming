#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the dlistint_t list.
 * @idx: The index at which the new node should be inserted.
 * @n: The data (integer) for the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current = *h;
    unsigned int i = 0;

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *h;
        if (*h)
            (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    while (current && i < idx - 1)
    {
        current = current->next;
        i++;
    }

    if (!current && i < idx - 1)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = current->next;
    if (current->next)
        current->next->prev = new_node;
    current->next = new_node;
    new_node->prev = current;

    return (new_node);
}
