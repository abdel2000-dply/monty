#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element.
 * @stack: The stack.
 * @line_n: The line number being executed.
 */
void sub(stack_t **stack, unsigned int line_n)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_n);
}

