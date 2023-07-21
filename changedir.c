#include "shell.h"
/**
 * change_dir - changes directory using chdir
 * @args: double pointer to arg
 * Return: 1
 */
int change_dir(char **args)
{
	char *path = args[1];
	char cwd[1024];

	    if (path == NULL)
	    {
		    path = getenv("HOME");
		    if (path == NULL)
		    {
			    printf("HOME environment variable not set.\n");
			    return 1;
		    }
	    }

    if (chdir(path) != 0)
    {
        printf("error\n");
        return 1;
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
	    setenv("PWD", cwd, 1);

	return (1);
}

