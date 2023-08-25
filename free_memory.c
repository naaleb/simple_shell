#include "shell.h"

/**
 * bfree – Function to free a pointer and NULL address
 * @ptr: The address of pointer to be freed
 *
 * Return: If freed 1, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}


