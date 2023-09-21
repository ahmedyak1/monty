#include "monty.h"


void funcc_swap(stack_t **header, unsigned int numi)
{
    stack_t *hea;
    int k = 0;
    int tmp;


    hea = *header;




    while (hea)
    {  
        k++;
        hea = hea->next;
       
    }
    if (k < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }


    hea = *header;
    tmp = hea->n;
    hea->n = hea->next->n;
    hea->next->n = tmp;
}




void funcc_add(stack_t **header, unsigned int numi)
{
    stack_t *h;
    int k = 0;
    int tmp;


    h = *header;
    while (h)
    {
        k++;
        h = h->next;
       
    }
    if (k < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }
    h = *header;
    tmp = h->n + h->next->n;
    h->next->n = tmp;
    *header = h->next;
    free(h);
}


void funcc_nop(stack_t **header, unsigned int numi)
{
    (void) header;
    (void) numi;
}


void funcc_sub(stack_t **header, unsigned int numi)
{
    stack_t *tmp;
    int k;
    int no;


    tmp = *header;
    for (no = 0; tmp != NULL; no++)
        tmp = tmp->next;
    if (no < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }
    tmp = *header;
    k = tmp->next->n - tmp->n;
    tmp->next->n = k;
    *header = tmp->next;
    free(tmp);
}


void funcc_mul(stack_t **header, unsigned int numi)
{
    stack_t *hea;
    int k = 0;
    int tmp;


    hea = *header;
    while (hea)
    {
        k++;
        hea = hea->next;
    }
    if (k < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", numi);
        fclose(global_var.file);
        free(global_var.conte);
        funcc_free_stack(*header);
        exit(EXIT_FAILURE);
    }
    hea = *header;
    tmp = hea->next->n * hea->n;
    hea->next->n = tmp;
    *header = hea->next;
    free(hea);
}

