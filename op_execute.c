#include "monty.h"
/**
 * op_execute - execution of the opcode.
 * @stack: the stack
 * @opc: opcode
 * @arg: ...
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
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{"sub", NULL},
		{"div", NULL},
		{"mul", NULL},
		{"mod", NULL},
		{"pchar", NULL},
		{"pstr", NULL},
		{"rotl", NULL},
		{"rotr", NULL},
		{NULL, NULL}
	};

	if (strcmp(opc, "push") == 0)
	{
		char *arg = strtok(NULL, " \n\t");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}
		opst[i].f(stack, line_n);
		return;
	}
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
