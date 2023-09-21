#include "monty.h"




int funcc_instru(stack_t **header,char *data, unsigned int number, FILE *file)
{
    instruction_t opst[] = {
                {"push", funcc_push},
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

