#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		printf("($) ");
		command = read_command();
		printf("You entered: %s", command);
		free(command);
	}

	return (0);
}

/**
 * read_command - Reads a line of input from the user
 *
 * Return: Pointer to the input line
 */
char *read_command(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return (line);
}

