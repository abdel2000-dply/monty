#include "monty.h"
/**
 * pall - pall opcode
 * @stack: the stack
 * @line_n: ...
 */
void pall(stack_t **stack, unsigned int line_n)
{
	stack_t *curr = *stack;
	(void)line_n;

	if (*stack == NULL)
		return;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

