#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
        listint_t *current, *temp;
        size_t count = 0;

        if (h == NULL || *h == NULL)
                return (0);

        current = *h;
        while (current != NULL)
        {
                count++;
                temp = current;
                current = current->next;
                free(temp);

                /* Check for a loop in the linked list */
                if (current == *h)
                {
                        *h = NULL;
                        break;
                }
        }

        return (count);
}
