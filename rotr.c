#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the stack head
 * @counter: Line number (unused)
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	stack_t *last = *head;
	while (last->next)
		last = last->next;

	last->next = *head;
	(*head)->prev = last->next;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev->prev = NULL;
}

