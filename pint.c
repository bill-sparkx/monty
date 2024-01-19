#include "monty.h"

/**
 * f_pint - Prints the top element of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_pint(stack_t **head, unsigned int counter)
{
    (*head == NULL) ? handle_stack_empty_error(counter, head) : printf("%d\n", (*head)->n);
}

