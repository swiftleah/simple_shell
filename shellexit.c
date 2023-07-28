#include "main.h"
/**
 * shell_exit - exits shell
 * @args: double pointer to arg
 * @user_exit_code: stores exit status
 * Return: 0
 */
int shell_exit(char **args, int user_exit_code)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		user_exit_code = atoi(args[1]);
	}
	exit_status = user_exit_code;
	exit(exit_status);
}


