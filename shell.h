#ifndef SHELL_H
#define SHELL_H

#define MAX_LIST 100

char *args[MAX_LIST];

/* Libraries: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes: */
void displayprompt(void);
void parseinput(char *line);
int execute_command(void);
int change_dir(char **args);
int shell_exit(void);
int num_builtins(void);

extern char *builtin_str[];
extern int (*builtin_func[])();

#endif
