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
	int i, status, is_builtin = 0;

	while (1)
	{
		displayprompt();
		line_size = getline(&line, &bufsize, stdin);

		if (line_size == EOF)
		{
			printf("EOF eached\n");
			break;
		}
		else if (line_size == 1)
			continue;

		parseinput(line);

		for (i = 0; i < num_builtins(); i++)
		{
			if (strcmp(args[0], builtin_str[i]) == 0)
			{
				is_builtin = 1;
				status = (*builtin_func[i])(args);
				if (status == 0)
					break;
			}
		}
	if (!is_builtin)
		execute_command();
	}

	free(line);
	return (EXIT_SUCCESS);
}

