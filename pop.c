#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_n: current line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;
	char *m;

	m = (mode == MODE_STACK) ? "stack" : "queue";
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty %s\n", line_n, m);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

