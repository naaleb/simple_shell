#include "shell.h"
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

/**
 * execute_command - Execute command line arguments.
 * @args: Array of arguments, with command at 0 index.
 */
void execute_command(char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			_exit(EXIT_FAILURE);
		}
	} else
	{

		wait(NULL);
	}
}

/**
 * main - Entry point for shell program.
 * Return: Always 0 (Success).
 */
int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];

	int arg_count = 0;
	char *token = strtok(line, " ");

	while (1)
	{
		printf("$ ");
		if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL)
		{
			break;
		}

		/* This removes newline character */
		line[strcspn(line, "\n")] = '\0';

		/* Tokenization of input line */
		while (token != NULL)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* end of the argument list */

		if (arg_count > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit(0);
			} else if (strcmp(args[0], "cd") == 0)
			{
				if (arg_count > 1)
				{
					if (chdir(args[1]) == -1)
					{
						perror("chdir");
					}
				} else
				{
					fprintf(stderr, "cd: missing argument\n");
				}
			} else
			{
				execute_command(args);
			}
		}
	}

	return (0);
}
