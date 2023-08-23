#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

/* Function prototypes */
char *read_command(void);
char **split_command(char *command);
void execute_command(char **args);
void free_args(char **args);

#endif /* MAIN_H */

