#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


extern char *arg;

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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int op_check(char *opc, unsigned int line_n);
void op_execute(stack_t **stack, char *opc, unsigned int line_n);

void free_stack(stack_t *stack);

void push(stack_t **stack, unsigned int line_n);
void pall(stack_t **stack, unsigned int line_n);
void pint(stack_t **stack, unsigned int line_n);
void pop(stack_t **stack, unsigned int line_n);
void swap(stack_t **stack, unsigned int line_n);
void add(stack_t **stack, unsigned int line_n);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_n);
void _div(stack_t **stack, unsigned int line_n);
void _mul(stack_t **stack, unsigned int line_n);
void mod(stack_t **stack, unsigned int line_n);
void pchar(stack_t **stack, unsigned int line_n);
void pstr(stack_t **stack, unsigned int line_n);

#endif
