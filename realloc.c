#include "shell.h"

/**
 * _memset – Funct. to fill memory with a constant byte
 * @s: Ptr to where memorry is located
 * @b: Fill *s with bytes
 * @n: Amount of bytes to fill
 * Return: (s) , Ptr to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree – Frees string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc – Funct to reallocates a block of memory
 * @ptr: Ptr to previous mallock block
 * @old_size: Byte size of previous block
 * @new_size: Byte size of new block
 *
 * Return: pointer to the old block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}


