#include "shell.h"
/**
 * change_dir - changes directory using chdir
 * @args: double pointer to arg
 * Return: 1
 */
int change_dir(char **args)
{
	if (args[1] == NULL)
	{
		printf("expected argument\n");
	}
	else
	{
		if(chdir(args[1]) != 0)
		{
			perror("Error occured whilst changing directory");
		}
		else
		{
			setenv("PWD", args[1], 1);
		}
	}
	return (0);
}

