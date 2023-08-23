#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


void shell_prompt(char **av, char **env);

#endif
