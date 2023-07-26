#include "main.h"
/**
 * displayprompt - displays '$' prompt for user input
 *
 * Return: nothing
 */
void displayprompt(void)
{
	const char *prompt = "$ ";
	if (write(STDOUT_FILENO, prompt, strlen(prompt)) < 0)
	{
		perror("Error writing prompt");
		exit(EXIT_FAILURE);
	}
}

