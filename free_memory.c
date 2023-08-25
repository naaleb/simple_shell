#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL
 * @ptr: Address of the pointer to free
 *
 * This function frees the memory occupied by the pointer and then sets
 * the pointer itself to NULL to avoid any potential dangling pointers.
 *
 * Return: 1 if memory was freed, 0 otherwise.
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

