#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t count = 0;

    tortoise = head;
    hare = head;

    /* Empty list or single node list */
    if (head == NULL)
        return (0);

    /* Detect the loop using Floyd's cycle detection algorithm */
    while (tortoise && hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            break;
    }

    /* If there's a loop, reset the tortoise and find the loop's start */
    if (tortoise == hare)
    {
        tortoise = head;
        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        printf("[%p] %d\n", (void *)tortoise, tortoise->n);
        printf("-> [%p] %d\n", (void *)hare, hare->n);
    }
    else
    {
        while (head)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            count++;

            head = head->next;
        }
    }

    return (count);
}
