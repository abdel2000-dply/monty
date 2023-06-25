#include "monty.h"
/**
 * op_execute - execution of the opcode.
 * @stack: the stack
 * @opc: opcode
 * @line_n: ...
 */
void op_execute(stack_t **stack, char *opc, unsigned int line_n)
{
	int i = 0;

	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", NULL},
		{"rotl", NULL},
		{"rotr", NULL},
		{NULL, NULL}
	};

	while (opst[i].opcode != NULL)
	{
		if (strcmp(opc, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_n);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opc);
	exit(EXIT_FAILURE);
}
