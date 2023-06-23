#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arg = NULL;

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
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
