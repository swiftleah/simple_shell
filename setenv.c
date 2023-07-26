#include "main.h"
/**
 * set_env - sets environment
 * @args: double pointer to argument
 * Return: 1
 */
int set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
		return (1);
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		write(STDERR_FILENO, "setenv error\n", 13);
		return (-1);
	}
	return (1);
}
/**
 * unset_env - unsets environment variable
 * @args: double pointer to argument
 * Return: 1
 */
int unset_env(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
		return (1);
	}
	if (unsetenv(args[1]) == -1)
	{
		write(STDERR_FILENO, "unsetenv error\n", 15);
		return (1);
	}
	return (1);
}

