#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	/* create temporary pointers to traverse the list */
	listint_t *temp = *head;
	listint_t *current = NULL;
	
	/* initialize a counter variable to keep track of the current index */
	unsigned int i = 0;

	/* if the list is empty, return failure */
	if (*head == NULL)
		return (-1);

	/* if the node to be deleted is the first node, update the head pointer and free the node */
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	/* traverse the list to the node just before the node to be deleted */
	while

