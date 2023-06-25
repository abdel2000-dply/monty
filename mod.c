#include "monty.h"

/**
 * mod - Computes the rest of the division.
 * @stack: The stack.
 * @line_n: The line number being executed.
 */
void mod(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}

