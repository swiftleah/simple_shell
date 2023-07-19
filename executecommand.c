#include "shell.h"
/**
 * execute_command - uses execve to execute parsed tokens
 * @args: double pointer to tokens that have been parsed
 * Return: nothing
 */
int execute_command(void)
{
	pid_t pid = fork();
	int i, status;
	char *path;
	char *path_copy;
	char *dir;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	if (pid == 0)
	{
		if (args[0][0] == '/' || args[0][0] == '.')
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("lsh");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			path = getenv("PATH");
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");

	while (dir != NULL)
            {
                char command_path[100];
                snprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);

                if (access(command_path, X_OK) == 0)
                {
                    if (execve(command_path, args, NULL) == -1)
                    {
                        perror("lsh");
                    }
                    exit(EXIT_FAILURE);
                }
                dir = strtok(NULL, ":");
            }
	free(path_copy);
	perror("command not found");
	exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("lsh");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
	return (1);
}
