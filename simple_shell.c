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
		char **args;

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

		args = parse_line(line);

		free(args);
	}

	free(line);
	exit(EXIT_SUCCESS);
}

/**
 * print_prompt - Display the shell prompt.
 * This function prints the prompt
 *		indicating that the shell is ready for input.
 */
void print_prompt(void)
{
	printf("$ ");
}

/**
 * parse_line - Parse the command line into arguments.
 * @line: The input command line.
 * Return: An array of pointers to the parsed arguments.
 */
char **parse_line(char *line)
{
	int bufsize = TOKEN_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOKEN_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}

