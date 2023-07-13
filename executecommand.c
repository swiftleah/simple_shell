#include "shell.h"
/**
 * execute_command - uses execve to execute parsed tokens
 * @args: double pointer to tokens that have been parsed
 * Return: nothing
 */
void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}
}
