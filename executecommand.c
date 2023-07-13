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

	if (args[0] == 0)
	{
		perror("Error: Empty Command");
		return (1);
	}
	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])();
		}
	}

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
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
	return 1;
}

