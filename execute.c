#include "monty.h"

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
        {"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
        {"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
        {"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
        {"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}
    };

    char *op = strtok(content, " \n\t");

    if (op && op[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    unsigned int i = 0;
    while (opst[i].opcode)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(stack, counter);
            return 0;
        }
        ++i;
    }

    if (op)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}

