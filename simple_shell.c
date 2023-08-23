#include "shell.h"

/**
 * main - shell program entry point
 * @ac: Argument count
 * @_av: Argument vector
 * @env: Environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **_av, char **env)
{
	if (ac == 1)
	{
		shell_prompt(_av, env);
	}
	return (0);
}
