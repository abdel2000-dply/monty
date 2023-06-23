#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_n: current line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if (*stack != NULL)
		(*stack)->prev = NULL;
}

