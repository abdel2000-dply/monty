#include "monty.h"

/**
 * _mul - Multiplies the second top element with the top element..
 * @stack: The stack.
 * @line_n: The line number being executed.
 */
void _mul(stack_t **stack, unsigned int line_n)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_n);
}

