#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_mul(stack_t **head, unsigned int counter)
{
    stack_t *top = *head;
    int len = 0;

    do
    {
        if (++len < 2)
        {
            handle_stack_too_short_error(counter, head);
        }

        int result = top->next->n * top->n;
        top->next->n = result;
        *head = top->next;
        free(top);
    } while (0);
}

