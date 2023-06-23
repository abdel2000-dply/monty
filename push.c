#include "monty.h"

/**
 * push - Adds an element to the top of the stack.
 * @stack: the slack
 * @line_n: ...
 */
void push(stack_t **stack, unsigned int line_n)
{
	stack_t *new;
	int value;

	value = atoi(arg);
	if (value == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
