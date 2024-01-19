#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void divide_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	/* Check if there are at least two elements in the stack */
	if (current == NULL || current->next == NULL)
	{
		handle_error_and_exit("can't div, stack too short", counter);
	}

	/* Check if the divisor (current->n) is not zero */
	if (current->n == 0)
	{
		handle_error_and_exit("division by zero", counter);
	}

	/* Perform the division and update the next element's value */
	current->next->n /= current->n;

	/* Remove the top element from the stack */
	*head = pop_stack(current);
}

/**
 * pop_stack - Removes the top element from the stack.
 * @current: Pointer to the current top element
 * @return: Pointer to the next element after the popped one
 */
stack_t *pop_stack(stack_t *current)
{
	stack_t *next_element = current->next;

	if (next_element)
	{
		next_element->prev = NULL;
	}

	free(current);

	return next_element;
}

/**
 * handle_error_and_exit - Prints an error message, cleans up resources, and exits.
 * @message: Error message to be printed
 * @counter: Line number
 */
void handle_error_and_exit(const char *message, unsigned int counter)
{
	fprintf(stderr, "L%d: %s\n", counter, message);
	fclose(bus.file);
	free(bus.content);
	free_stack(bus.stack);
	exit(EXIT_FAILURE);
}

