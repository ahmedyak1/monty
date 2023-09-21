#include "monty.h"




int funcc_instru(stack_t **header,char *data, unsigned int number, FILE *file)
{
    instruction_t opst[] = {
                {"push", funcc_push},
                {"pall", funcc_pall},
                {"swap", funcc_swap},
                {"add", funcc_add},
                {"pint", funcc_pint},
                {"pop", funcc_pop},
                {"nop", funcc_nop},
                {"sub", funcc_sub},
                {"mul", funcc_mul},
                {NULL, NULL}
                };
    unsigned int i = 0;
    char *ooop;


    ooop = strtok(data, " \n\t");
    if (ooop && ooop[0] == '#')
        return (0);
    global_var.argu = strtok(NULL, " \n\t");
    while (opst[i].opcode && ooop)
    {
        if (strcmp(ooop, opst[i].opcode) == 0)
        {   opst[i].f(header, number);
            return (0);
        }
        i++;
    }
    if (opst[i].opcode == NULL &&  ooop )
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", number, ooop);
        fclose(file);
        free(data);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE); }
    return (1);
}


void funcc_pall(stack_t **header, unsigned int numi)
{
    stack_t *hea;
    (void)numi;


    hea = *header;
    if (!hea)
        return;
    while (hea)
    {
        printf("%d\n", hea->n);
        hea = hea->next;
    }
}


void funcc_pint(stack_t **header, unsigned int numi)
{
    if (!*header)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*header)->n);
}


void funcc_pop(stack_t **header, unsigned int numi)
{
    stack_t *hea;


    if (!*header)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }
    hea = *header;
    *header = hea->next;
    free(hea);
}

