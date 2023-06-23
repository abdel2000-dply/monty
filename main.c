#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *arg = NULL;

/**
 * op_check - checks the opcode.
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
		return 1;
	}
	else if (strcmp(opc, "pall") == 0)
	{
		return 2;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opc);
	exit(EXIT_FAILURE);
}

/**
 * op_execute - execution of the opcode.
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
			/* Add more cases for other opcodes */
		default:
			break;
	}
}
/**
 * main - entry point
 * @argc: number of arguments.
 * @argv: monty file location
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL, *opc, *arg;
	size_t len = 0;
	unsigned int line_n = 0;
	int read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Cant't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_n++;
		opc = strtok(line, " \t\n");
		if (opc == NULL)
			continue; /* skip a line */
		arg = strtok(NULL, " \t\n");
		op_execute(&stack, opc, arg, line_n);
	}
	fclose(file);

	return (EXIT_SUCCESS);
}
