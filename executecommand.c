#include "shell.h"
/**
 * execute_command - executes command
 *
 * Return: 1
 */

int execute_command(void)
{
	pid_t pid = fork();
	int i, status;

	if (args[0] == NULL)
		return (1);

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}

	if (pid == 0)
	{
		if (args[0][0] == '/' || args[0][0] == '.')
		{
			char *command_path = find_command_path(args[0]);

			if (command_path != NULL)
				return (execute_command_path(command_path, args));
		}
		else
		{
			char *command_path = find_command_path(args[0]);

			if (command_path != NULL)
				return (execute_command_path(command_path, args));
		}
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("lsh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
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

	while (dir != NULL)
	{
		char command_path[100];

		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(command_path));
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

int execute_command_path(const char *command_path, char *const args[])
{
	if (execve(command_path, args, NULL) == -1)
	{
		perror("lsh");
	}
	exit(EXIT_FAILURE);
}
