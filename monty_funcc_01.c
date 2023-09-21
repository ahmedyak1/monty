#include "monty.h"




void funcc_add_node(stack_t **header, int n)
{


    stack_t *nm;
    stack_t *tempo;


    tempo = *header;
    nm = malloc(sizeof(stack_t));
    if (nm == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (tempo)
        tempo->prev = nm;


    nm->n = n;
    nm->next = *header;
    nm->prev = NULL;
    *header = nm;
}


void funcc_add_queue(stack_t **header, int n)
{
    stack_t *nm;
    stack_t *tempo;


    tempo = *header;
    nm = malloc(sizeof(stack_t));


    if (!nm)
    {
        printf("Error\n");
    }


    nm->n = n;
    nm->next = NULL;


    if (tempo)
    {
        while (tempo->next)
            tempo = tempo->next;
    }
    if (tempo)
    {
        tempo->next = nm;
        nm->prev = tempo;
    }
    else
    {
        *header = nm;
        nm->prev = NULL;
    }
}


void funcc_free_stack(stack_t *header)
{
    stack_t *tempo;
    tempo = header;
    while (header)
    {
        tempo = header->next;


        free(header);
        header = tempo;


    }
}




void funcc_push(stack_t **header, unsigned int numi)
{
    int k;
    int m = 0;
    int flagg = 0;


    if (global_var.argu)
    {
        if (global_var.argu[0] == '-')
            m++;


        for (m=0 ; global_var.argu[m] != '\0'; m++)
        {
            if (global_var.argu[m] < 48 || global_var.argu[m] > 57)
                flagg = 1;
        }


        if (flagg == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", numi);
            fclose(global_var.file);
            free(global_var.conte);
            funcc_free_stack(*header);
            exit(EXIT_FAILURE); }
        }
    else


    {
        fprintf(stderr, "L%d: usage: push integer\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE); }
    k = atoi(global_var.argu);
    if (global_var.num != 0)
        funcc_add_queue(header, k);
    else
        funcc_add_node(header, k);
}

