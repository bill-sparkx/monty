#include "monty.h"

/**
 * addnode - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack
 * @n: New value to be stored in the node
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        handle_memory_error();
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = (*head == NULL) ? NULL : *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

/**
 * handle_memory_error - Handles memory allocation errors.
 */
void handle_memory_error(void)
{
    fprintf(stderr, "Error: Unable to allocate memory\n");
    exit(EXIT_FAILURE);
}

