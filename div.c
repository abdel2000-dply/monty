#include "monty.h"

/**
 * _div - Divides the second top element by the top element.
 * @stack: The stack.
 * @line_n: The line number being executed.
 */
void _div(stack_t **stack, unsigned int line_n)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_n);
}

