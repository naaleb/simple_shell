#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Define constants */
#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define DELIMITERS " \t\n\r\a"

/* Function prototypes */
void print_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
void free_args(char **args);

#endif /* SHELL_H */

