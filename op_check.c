#include "monty.h"

/**
 * op_check - checks the opcode.
 * @opc: opcode
 * @arg: ...
 * @line_n: ...
 * Return: flag
 */
int op_check(char *opc, char *arg, unsigned int line_n)
{
	if (strcmp(opc, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}
		return (1);
	}
	else if (strcmp(opc, "pall") == 0)
	{
		return (2);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opc);
	exit(EXIT_FAILURE);
}
