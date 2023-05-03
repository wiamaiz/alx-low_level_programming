#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	/* create temporary pointers to keep track of the previous and next nodes */
	listint_t *prev = NULL;
	listint_t *next = NULL;

	/* iterate through each node in the list */
	while (*head)
	{
		/* set 'next' to point to the node following the current node */
		next = (*head)->next;

		/* set the 'next' pointer of the current node to point to the previous node */
		(*head)->next = prev;

		/* set 'prev' to the current node */
		prev = *head;

		/* set the head pointer to point to 'next' */
		*head = next;
	}

	/* set the head pointer to point to the last node in the reversed list (which is now the first node) */
	*head = prev;

	/* return the head pointer */
	return (*head);
}

