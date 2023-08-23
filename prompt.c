#include "shell.h"

#define MAX_COMMAND 10

/**
 * shell_prompt - Display a shell prompt and execute commands.
 * @av: The argument vector.
 * @env: The environment variables.
 */
void shell_prompt(char **_av, char **env)
{
	size_t n = 0;
	ssize_t num_char;
	char *string = NULL;
	char *argv[MAX_COMMAND];
	pid_t child_pid;
	int status,j = 0;
	(void)_av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (string[num_char - 1] == '\n')
			string[num_char - 1] = '\0';

		argv[j] = strtok(string, " ");
		while (argv[j] && j < MAX_COMMAND - 1)
		{
			argv[++j] = strtok(NULL, " ");
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(string);
}

