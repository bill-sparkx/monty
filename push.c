#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_push(stack_t **head, unsigned int counter)
{
    if (!bus.arg || !is_valid_integer(bus.arg))
        handle_push_error(counter, head);

    int n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

/**
 * handle_push_error - Handles errors during push operation.
 * @counter: Line number
 * @head: Pointer to the stack head
 */
void handle_push_error(unsigned int counter, stack_t **head)
{
    fprintf(stderr, "L%d: usage: push integer\n", counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * is_valid_integer - Checks if the string represents a valid integer.
 * @str: String to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(char *str)
{
    if (str[0] == '-')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

