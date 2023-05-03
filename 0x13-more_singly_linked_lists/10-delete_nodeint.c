int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *prev_node, *current_node;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current_node = *head;

    if (index == 0)
    {
        *head = current_node->next;
        free(current_node);
        return (1);
    }

    for (i = 0; i < index; i++)
    {
        prev_node = current_node;
        current_node = current_node->next;
        if (current_node == NULL)
            return (-1);
    }

    prev_node->next = current_node->next;
    free(current_node);
    return (1);
}

