#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

