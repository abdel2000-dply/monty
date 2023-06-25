#include "monty.h"

/**
 * free_stack - Frees the memory occupied by a stack.
 * @stack: The stack to be freed.
 */
void free_stack(stack_t *stack)
{
	stack_t *curr = stack;
	stack_t *next;

	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

