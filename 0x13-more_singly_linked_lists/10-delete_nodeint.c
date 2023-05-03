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
    if (*head == NULL) {
        return -1; // if the list is empty, return -1 indicating failure
    }

    if (index == 0) {
        listint_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1; // if the first node needs to be deleted, update the head pointer and return 1 indicating success
    }

    listint_t *current = *head;
    for (unsigned int i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return -1; // if the end of the list is reached before the target node is found, return -1 indicating failure
        }
        current = current->next;
    }

    listint_t *temp = current->next;
    current->next = temp->next;
    free(temp);
    return 1; // delete the target node, update the links, and return 1 indicating success
}

