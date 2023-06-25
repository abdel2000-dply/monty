#include "monty.h"

/**
 * is_number - Checks if a string is a valid number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(const char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;

	if (str[i] == '\0')
		return (0);

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
