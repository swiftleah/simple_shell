#include "main.h"
/**
 * execute_command - executes command
 * @args: arguments
 * Return: 1
 */

int execute_command(char *args[MAX_LIST])
{
	char *command_path = NULL;
	pid_t pid;
	int status;

		if (args[0][0] == '/' || args[0][0] == '.')
			command_path = find_command_path(args[0]);
		else
			command_path = find_command_path(args[0]);
		if (command_path == NULL)
		{
			perror("command not found");
			return (127);
		}

		pid = fork();

		if (pid == 0)
		{
			return execute_command_path(command_path, args);
		}
		else if (pid < 0)
			return (127);

		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));

			if (WIFEXITED(status))
				return WEXITSTATUS(status);
			else
				return (127);
		}
		return (0);
}

/**
 * find_command_path - finds command PATH
 * @command: command given by user
 * Return: path
 */

char *find_command_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char command_path[1000];
	size_t dir_len;
	size_t command_len;

	if (access(command, X_OK) == 0)
		return (strdup(command));

	while (dir != NULL)
	{
		dir_len = strlen(dir);
		command_len = strlen(command);

		if (dir_len + command_len + 1 < sizeof(command_path))
		{
			strcpy(command_path, dir);
			strcat(command_path, "/");
			strcat(command_path, command);
			if (access(command_path, X_OK) == 0)
			{
				free(path_copy);
				return (strdup(command_path));
			}
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * execute_command_path - executes command where path is needed
 * @command_path: command path
 * @args: args
 * Return: EXIT
 */

int execute_command_path(char *command_path, char *const args[])
{
	if (execve(command_path, args, environ) == -1)
		perror("lsh");
	if (execve(command_path, args, NULL) == -1)
	{
		perror("lsh");
	}
	return (0);
}

