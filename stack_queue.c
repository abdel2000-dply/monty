#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO), default behavior.
 *
 * @stack: The stack.
 * @line_n: Line number.
 */
void _stack(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;

	mode = MODE_STACK;
}
/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @stack: The stack.
 * @line_n: Line number.
 */
void _queue(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;

	mode = MODE_QUEUE;
}
