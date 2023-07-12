#include "shell.h"
/**
 * parseinput - tokenizes input from user
 * @line: char pointer
 * @bufsize: buffer size
 *
 * Return: nothing
 */
void parseinput(char *line, size_t bufsize)
{
	char *token = strtok(line, " ");
	char **args = malloc(sizeof(char *) * bufsize);
	int arg_count = 0;

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	execute_command(args);
	free(args);
}

