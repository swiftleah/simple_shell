#include "main.h"
/**
 * parseinput - tokenizes input from user
 * @line: char pointer
 * @args: pointer to argument
 * Return: nothing
 */
void parseinput(char *line, char *args[MAX_LIST])
{
	int i = 0;
	char *token = strtok(line, " \n");

	if (i >= MAX_LIST)
	{
		perror("Too many arguments");
		return;
	}

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	free(token);
	args[i] = NULL;
}
