/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *prev;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    prev = NULL;
    for (i = 0; i < index && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }
    if (i < index || current == NULL)
        return (-1);

    if (prev != NULL)
        prev->next = current->next;
    else
        *head = current->next;

    free(current);

    return (1);
}

