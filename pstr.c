#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number (unused)
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter; /* Unused parameter */

	while (current && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

