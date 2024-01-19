#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_swap(stack_t **head, unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    stack_t *top = *head;
    stack_t *second = top->next;

    top->next = second->next;
    second->prev = top->prev;

    if (top->next != NULL)
    {
        top->next->prev = top;
    }

    if (second->prev != NULL)
    {
        second->prev->next = second;
    }

    top->prev = second;
    second->next = top;

    *head = second;
}

