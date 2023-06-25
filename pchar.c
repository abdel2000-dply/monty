#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: The stack.
 * @line_n: The line number being executed.
 */
void pchar(stack_t **stack, unsigned int line_n)
{
	int v;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}

	v = (*stack)->n;

	if (v < 0 || v > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", v);
}

