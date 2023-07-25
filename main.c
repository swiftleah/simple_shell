#include "shell.h"
/**
 * main - main function of shell
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t line_size;
	int i;

	while (1)
	{
		displayprompt();
		line_size = custom_getline(&line, &bufsize, stdin);

		if (line_size == EOF)
		{
			printf("EOF eached\n");
			break;
		}
		else if (line_size == 1)
			continue;
		parseinput(line);
		if (args[0] == NULL)
			continue;
		else if (strcmp(args[0], "cd") == 0)
			change_dir(args);
		else if (strcmp(args[0], "exit") == 0)
			shell_exit(args);
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
				execute_command();
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}

