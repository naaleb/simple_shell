#include "shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * main - Simple UNIX command line interpreter
 *
 * Description: Displays prompt, reads input, and executes commands.
 *              Supports simple error handling.
 *
 * Return: Always 0(success).
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[2];
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';

		args[0] = input;
		args[1] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(args[0], args, NULL);

			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child process exited: %d\n", WEXITSTATUS(status));
			}
		}
	}

	return (0);
}
