#include "main.h"
/**
 * error_exit - error message and exit
 * Return: nothing
 */
void error_exit(void)
{
	perror("Memory allocation failed");
	exit(EXIT_FAILURE);
}

