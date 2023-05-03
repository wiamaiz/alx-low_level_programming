#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	/* initialize the tortoise and hare pointers */
	tortoise = head->next;
	hare = (head->next)->next;

	/* iterate through the list until the hare pointer meets the tortoise pointer */
	while (hare)
	{
		if (tortoise == hare)
		{
			/* if the pointers meet, reset the tortoise pointer to the head node */
			tortoise = head;

			/* iterate through the list with both pointers until they meet again */
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			/* iterate through the rest of the loop to get the total number of nodes in the loop */
			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			 }

			/* return the number of unique nodes in the loop */
			return (nodes);
		}

		/* update the tortoise and hare pointers */
		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	/* return 0 if the list is not looped */
	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	/* check if the list is looped and get the number of unique nodes */
	nodes = looped_listint_len(head);

	/* if the list is not looped, print each node and increment the node count */
	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	/* if the list is looped, print each node up to the loop point and the loop point itself */
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	/* return the number of nodes in the list */
	return (nodes);
}

