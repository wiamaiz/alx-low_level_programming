#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (!head)
		return (NULL);

	listint_t *current = head;
	listint_t *runner = head;

	while (current && runner && runner->next)
	{
		runner = runner->next->next;
		current = current->next;
		if (runner == current)
		{
			current = head;
			while (current != runner)
			{
				current = current->next;
				runner = runner->next;
			}
			return (runner);
		}
	}

	return (NULL);
}

