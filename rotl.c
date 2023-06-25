#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: the stack.
 * @line_n: Current line number.
 */
void rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *last;
	(void)line_n;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
