#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: The stack.
 * @line_n: The line number.
 */
void add(stack_t **stack, unsigned int line_n)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_n);
}
