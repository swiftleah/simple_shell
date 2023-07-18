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
	int status;
	ssize_t line_size;

	do
	{
		displayprompt();
		line_size = getline(&line, &bufsize, stdin);

		if (line_size == -1)
		{
			if (line == NULL || (line[0] == '\0' || line[0] == '\n'))
			{
				printf("End of file reached.\n");
				break;
			}
			else
			{
				perror("Error: End of file reached");
				exit(EXIT_FAILURE);
			}
		}
		parseinput(line);
		status = execute_command();
	} while (status);

	free(line);
	return (EXIT_SUCCESS);
}

