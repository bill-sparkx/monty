#include "monty.h"

/**
 * f_queue - Sets the queue mode (FIFO).
 * @head: Pointer to the stack head
 * @counter: Line number
 */
void f_queue(stack_t **head, unsigned int counter)
{
    do
    {
        (void)head;
        (void)counter;
        bus.lifi = 1;
    } while (0);
}

/**
 * addqueue - Adds a new node to the tail of the stack.
 * @head: Pointer to the head of the stack
 * @n: New value to be stored in the node
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        handle_memory_error();
    }

    new_node->n = n;
    new_node->next = NULL;

    stack_t *aux = *head;
    if (aux)
    {
        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = new_node;
        new_node->prev = aux;
    }
    else
    {
        *head = new_node;
        new_node->prev = NULL;
    }
}

