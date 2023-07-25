#ifndef SHELL_H
#define SHELL_H

#define MAX_LIST 100
#define BUFFER_SIZE 1024

extern char **environ;

/* Libraries: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes: */
void displayprompt(void);
void parseinput(char *line, char *args[MAX_LIST]);
/* Execute command: */
int execute_command(char *args[MAX_LIST]);
char *find_command_path(const char *command);
int execute_command_path(const char *command_path, char *const args[]);

int change_dir(char **args);
int shell_exit(char **args);
int num_builtins(void);
int print_env(void);
/* Custom Getline: */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void initialize_lineptr(char **lineptr, size_t *n);
ssize_t read_buffer(char **lineptr, char buffer[], size_t *buffer_index,
		ssize_t *bytes_in_buffer, int *found_newline, FILE *stream);
int expand_lineptr(char **lineptr, size_t *n);

extern char *builtin_str[];
extern int (*builtin_func[])();

#endif
