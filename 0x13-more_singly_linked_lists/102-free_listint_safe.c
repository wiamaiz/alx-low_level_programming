#include "lists.h"

/**
 * free_listint_safe - Frees a linked list, even if it has a loop.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0;
	int offset;
	listint_t *current, *next_node;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		offset = *h - (*h)->next;
		if (offset > 0)
		{
			current = *h;
			next_node = (*h)->next;
			*h = next_node;
			free(current);
			node_count++;
		}
		else
		{
			node_count++;
			free(*h);
			*h = NULL;
			break;
		}
	}

	*h = NULL;

	return (node_count);
}

