#include "shell.h"

/**
 * _eputs – Function to print an input string
 * @str: String to be printed
 *
 * Return: Null
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes character c to stderr
 * @c: Char to print
 *
 * Return: 1 on Success
 * -1 on error, and error set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd – Writes character c to a given file descriptor
 * @c: Character to print
 * @fd: File descriptor to write to
 *
 * Return: 1 on success
 * -1 on error, and error  is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd – Func to print an input string
 * @str: The string to print
 * @fd: File descriptor to be written to
 *
 * Return: Number of chars
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

