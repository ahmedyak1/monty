#ifndef MONTY_H
#define MONTY_H


#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct globals_var
{
    FILE *file;
    char *argu;
    char *conte;
    int num;
}  globals_var;


extern globals_var global_var;




void funcc_push(stack_t **header, unsigned int numi);
void funcc_pall(stack_t **header, unsigned int numi);
void funcc_free_stack(stack_t *header);
void funcc_add_queue(stack_t **header, int n);
void funcc_add_node(stack_t **header, int n);
int  funcc_instru(stack_t **header, char *data, unsigned int number, FILE *file);
void funcc_pint(stack_t **header, unsigned int numi);
void funcc_pop(stack_t **header, unsigned int numi);
void funcc_swap(stack_t **header, unsigned int numi);
void funcc_add(stack_t **header, unsigned int numi);
void funcc_nop(stack_t **header, unsigned int numi);
void funcc_sub(stack_t **header, unsigned int numi);
void funcc_mul(stack_t **header, unsigned int numi);






#endif

