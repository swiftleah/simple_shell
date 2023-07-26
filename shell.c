#include "main.h"
/**
 * process_input - processes input from user
 * Return: nothing
 */
void process_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t line_size;
	char *args[MAX_LIST];

	while (1)
	{
		line = NULL;

		displayprompt();
		line_size = custom_getline(&line, &bufsize, stdin);

		if (line_size == EOF)
			break;
		else if (line_size == 1)
			continue;
		parseinput(line, args);
		if (args[0] == NULL)
			continue;
		else
			execute_args(args);
		free(line);
	}
}
/**
 * execute_args - executes builtin or command
 * @args: arguments
 * Return: nothing
 */
void execute_args(char *args[MAX_LIST])
{
	int i;

	if (strcmp(args[0], "cd") == 0)
		change_dir(args);
	else if (strcmp(args[0], "exit") == 0)
		shell_exit(args);
	else if (strcmp(args[0], "setenv") == 0)
		set_env(args);
	else if (strcmp(args[0], "unsetenv") == 0)
		unset_env(args);
	else
	{
		for (i = 0; i < num_builtins(); i++)
		{
			if (strcmp(args[0], builtin_str[i]) == 0)
			{
				(*builtin_func[i])(args);
				break;
			}
		}
		if (i == num_builtins())
			execute_command(args);
	}
}

/**
 * main - main function
 * Return: exit
 */
int main(void)
{
	process_input();
	return (EXIT_SUCCESS);
}

