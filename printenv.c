#include "shell.h"
/**
 * print_env - prints environment
 * Return: 1
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) < 0)
		{
			perror("Error writing environemnt variable");
			return (-1);
		}
		if (write(STDOUT_FILENO, "\n", 1) < 0)
		{
			perror("Error writing newline");
			return (-1);
		}
	}
	return (1);
}
