#define _POSIX_C_SOURCE 200809L
#include "monty.h"

char *arg = NULL;
int mode = MODE_STACK;

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
	char *line = NULL, *opc;
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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_n++;
		if (line[0] == '#' || line[0] == '\n')
			continue;
		opc = strtok(line, " \n\t\r");
		if (opc == NULL)
			continue; /* skip a line */
		arg = strtok(NULL, " \n\t\r");
		if (opc[0] != '#')
			op_execute(&stack, opc, line_n);
	}
	free(line);
	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
