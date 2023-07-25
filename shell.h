#ifndef SHELL_H
#define SHELL_H

#define MAX_LIST 100
#define BUFFER_SIZE 1024

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
/* Execute command: */
int execute_command(void);
char *find_command_path(const char *command);
int execute_command_path(const char *command_path, char *const args[]);

int change_dir(char **args);
int shell_exit(char **args);
int num_builtins(void);
int print_env(void);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

extern char *builtin_str[];
extern int (*builtin_func[])();

#endif
