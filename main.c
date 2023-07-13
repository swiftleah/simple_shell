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
	ssize_t input;

	while (1)
	{
		displayprompt();
		input = getline(&line, &bufsize, stdin);

		if (input == -1)
		{
			if (line == NULL || (line[0] == '\0' || line[0] == '\n'))
			{
				printf("End of file reached.\n");
			}
			else
			{
				perror("Error: End of file reached\n");
			}
			free(line);
			return (1);
		}
	}
		parseinput(line, bufsize);
		free(line);
		return (0);
}

