#include "monty.h"

/**
 * f_pchar - Prints the char at the top of the stack, followed by a new line.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        handle_error_and_exit("can't pchar, stack empty", counter);
    }

    stack_t *top = *head;

    if (top->n > 127 || top->n < 0)
    {
        handle_error_and_exit("can't pchar, value out of range", counter);
    }

    putchar(top->n);
    putchar('\n');
}

