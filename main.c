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

	do
	{
		displayprompt();
		if (getline(&line, &bufsize, stdin) == -1)
		{
			if (line == NULL || (line[0] == '\0' || line[0] == '\n'))
			{
				printf("End of file reached.\n");
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

