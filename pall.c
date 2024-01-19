#include "monty.h"

/**
 * f_pall - Prints the elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number (unused)
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter; /* Unused parameter */

	if (current == NULL)
		return;

	do
	{
		printf("%d\n", current->n);
		current = current->next;
	} while (current != NULL);
}

