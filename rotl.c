#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: the stack.
 * @line_n: Current line number.
 */
void rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *last, *temp;
	(void)line_n;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	temp = last->next;
	while (last->next != NULL)
	{
		last = last->next;
		temp = last->next;
	}
	last->next = *stack;
	(*stack)->prev = last;
	(*stack)->next = NULL;
	*stack = temp;
	(*stack)->prev = NULL;
}
