#include "shell.h"
/**
 * parseinput - tokenizes input from user
 * @line: char pointer
 * @bufsize: buffer size
 *
 * Return: nothing
 */
void parseinput(char *line)
{
	int i = 0;
	char *token = strtok(line, " \n");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	args[i] = NULL;
}

