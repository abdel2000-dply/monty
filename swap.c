#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The stack.
 * @line_n: The line number.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
