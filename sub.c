#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_sub(stack_t **head, unsigned int counter)
{
    if (stack_length(*head) < 2)
    {
        handle_stack_too_short_error(counter, head);
    }

    stack_t *top = *head;
    int result = top->next->n - top->n;
    top->next->n = result;
    *head = pop_stack(top);
}

