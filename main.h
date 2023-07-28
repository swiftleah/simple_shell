#ifndef MAIN_H
#define MAIN_H

#define MAX_LIST 100
#define BUFFER_SIZE 10000
#define MAX_BUFFER_LENGTH 1024
#define MAX_ARGS 100
#define MAX_ARG_LENGTH 50

/* Libraries: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;
extern int exit_status;

/* Prototypes: */
int shell_exit(char **args, int user_exit_code);
void process_input(int show_prompt);
void execute_args(char *args[MAX_LIST]);
void displayprompt(int show_prompt);
void parseinput(char *line, char *args[MAX_LIST]);
/* Execute command: */
int execute_command(char *args[MAX_LIST]);
char *find_command_path(const char *command);
int execute_command_path(char *command_path, char *const args[]);

int change_dir(char **args);
int shell_exit(char **args, int user_exit_code);
int num_builtins(void);
int print_env(void);
int error_msg(void);
/* Custom Getline: */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void initialize_lineptr(char **lineptr, size_t *n);
ssize_t read_buffer(char **lineptr, char buffer[], size_t *buffer_index,
		ssize_t *bytes_in_buffer, int *found_newline, FILE *stream);
int expand_lineptr(char **lineptr, size_t *n);
int set_env(char **args);
int unset_env(char **args);
void handle_sigint(int sig);
void process_args(int argc, char *argv[]);

extern char *builtin_str[];
extern int (*builtin_func[])();

#endif
