#include "shell.h"

/**
 * interactive - Returns true if shell is in interactive mode
 * @info: Struct address
 *
 * Return: 1 if interactive in  mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Determine if char is a delimeter
 * @c: char to check
 * @delim: The delimeter string
 * Return: return 1 if true, if false return 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - check if char is alphabetic
 * @c: The char to input
 * Return:1 if c is alphabetic, otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'b' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s:The string to be converted
 * Return:  0 if no numbers in string,  otherwise converted number
 */

int _atoi(char *s)
{
	int j, i =0, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[i] != '\0' && flag != 2; j++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

