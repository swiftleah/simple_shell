#include "main.h"
/**
 * shell_exit - exits shell
 * @args: double pointer to arg
 * @user_exit_code: stores exit code
 * Return: 0
 */
int shell_exit(char **args, int user_exit_code)
{
	if (args[1] != NULL)
	{
		user_exit_code = atoi(args[1]);
	}
	exit_status = user_exit_code;
	exit(exit_status);
}


