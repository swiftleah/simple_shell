#include "shell.h"
/**
 * change_dir - changes directory using chdir
 * @args: double pointer to arg
 * Return: 1
 */
int change_dir(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *path = args[1];
		
		if (path == NULL)
		{
			path = getenv("HOME");
		}

		if (chdir(path) != 0)
		{
			perror("Error");
		}
		else
		{
			setenv("PWD", path, 1);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}

	/*if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (chdir(home_dir) != 0)
			perror("Error");
		else
		{
			setenv("PWD", home_dir, 1);
		}
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
	}*/
	return (1);
}

