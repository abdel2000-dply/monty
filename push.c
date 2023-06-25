#include "monty.h"

/**
 * push_stack - Adds an element to the top of the stack.
 * @stack: Pointer to the head of the stack
 * @value: Value to be pushed
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * push_queue - Adds an element to the rear of the queue.
 * @stack: Pointer to the head of the queue
 * @value: Value to be pushed
 */
void push_queue(stack_t **stack, int value)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	if (*stack != NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
	{
		*stack = new;
	}
}

/**
 * push - Adds an element to the top of the stack.
 * @stack: the slack
 * @line_n: ...
 */
void push(stack_t **stack, unsigned int line_n)
{
	int value;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}

	if (!is_number(arg))
	{
		fprintf(stderr,"L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	if (value == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}

	if (mode == MODE_STACK)
		push_stack(stack, value);
	else if (mode == MODE_QUEUE)
		push_queue(stack, value);
}
