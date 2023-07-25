#include "shell.h"
/**
 * print_env - prints environment
 * Return: 1
 */
int print_env(void)
{
	int i;
	char **environ = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}
