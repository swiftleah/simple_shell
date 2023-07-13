#ifndef SHELL_H
#define SHELL_H

/* Libraries: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes: */
void displayprompt(void);
void parseinput(char *line, size_t bufsize);
void execute_command(char **args);

#endif
