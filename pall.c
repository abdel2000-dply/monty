#include "monty.h"
/**
  *
  */
void pall(stack_t **stack, unsigned int line_n)
{
	stack_t *curr = *stack;
	(void)line_n;

	if (*stack == NULL)
		return;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

