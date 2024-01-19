#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_add(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		handle_error_and_exit("can't add, stack too short", counter);
	}

	stack_t *top = *head;
	stack_t *next = top->next;

	int result = top->n + next->n;
	next->n = result;

	*head = pop_stack(top);
}
