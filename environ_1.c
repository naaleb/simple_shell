#include "shell.h"

/**
 * _myenv - Function to print current environ
 * @info: Struct containing potential arg to maintain constant funct prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Get value of an environ variable
 * @info:  Struct that contains potential arguments.
 * @name: variable name
 *
 * Return: Value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -  Function that Initialize a new environ variable,
 *             or modify an existing one
 * @info: Struct containing potential arguments.
 *  Return: Always (0)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect no of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -  Function to remove an environment variable
 * @info: Struct containing potential arg, used to maintain funct. prototype.
 * Return: Always (0)
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list – Function that populates environ linked list
 * @info: Structure that contains potential arguments
 * Return: Always (0)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

