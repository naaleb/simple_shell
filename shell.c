#include "shell.h"

/**
 * main - Entry point for the simple shell loop.
 * This function is the central loop of the simple shell program.
 * It manages user input, command parsing, execution, and output.
 * The loop continues until the user exits the shell.
 * Return: 0 on successful execution.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		print_prompt();

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		printf("You entered: %s", line);
	}

	free(line);
	exit(EXIT_SUCCESS);
}

/**
 * print_prompt - Display the shell prompt.
 * This function prints the prompt
 *	indicating that the shell is ready for input.
 */
void print_prompt(void)
{
	printf("$ ");
}

