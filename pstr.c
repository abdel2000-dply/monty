#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: The stack.
 * @line_n: The line number.
 */
void pstr(stack_t **stack, unsigned int line_n)
{
	stack_t *curr = *stack;
	(void)line_n;

	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}

