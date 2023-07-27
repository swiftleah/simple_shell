#include "main.h"
/**
 * change_dir - changes directory using chdir
 * @args: double pointer to arg
 * Return: 1
 */
int change_dir(char **args)
{
	static char prev_dir[1024] = "";
	char *path = args[1];
	char cwd[1024];

	if (path == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			perror("HOME environment variable not set.");
			return (1);
		}
	}
	else if (strcmp(path, "-") == 0)
	{
		if (prev_dir[0] == '\0')
		{
			perror("Previous directory not available.");
			return (1);
		}
		path = prev_dir;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	if (chdir(path) != 0)
	{
		perror("Error: Directory not found.");
		return (1);
	}
	if (strcmp(path, "-") !=0)
	{
		strncpy(prev_dir, cwd, sizeof(prev_dir));
		prev_dir[sizeof(prev_dir) - 1] = '\0';
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		setenv("PWD", cwd, 1);
	else
	{
		perror("getcwd");
	}
	return (1);
}

