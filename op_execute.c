#include "monty.h"
/**
 * op_execute - execution of the opcode.
 * @stack: the stack
 * @opc: opcode
 * @arg: ...
 * @line_n: ...
 */
void op_execute(stack_t **stack, char *opc, char *arg, unsigned int line_n)
{
	int op_flag = op_check(opc, arg, line_n);

	switch (op_flag)
	{
		case 1: /* Push opcode */
			push(stack, line_n);
			break;
		case 2: /* Pall opcode */
			pall(stack, line_n);
			break;
		case 3: /* Pint opcode */
			pint(stack, line_n);
			break;
		default:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opc);
			exit(EXIT_FAILURE);
			break;
	}
}
