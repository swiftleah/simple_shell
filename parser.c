#include "shell.h"
/**
 * parseinput - tokenizes input from user
 * @line: char pointer
 *
 * Return: nothing
 */
void parseinput(char *line, char *args[MAX_LIST])
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

