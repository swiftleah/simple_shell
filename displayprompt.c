#include "main.h"
/**
 * displayprompt - displays '$' prompt for user input
 *
 * Return: nothing
 */
void displayprompt(int show_prompt)
{
	const char *prompt = "$ ";
	if (show_prompt)
	{
		if (write(STDOUT_FILENO, prompt, strlen(prompt)) < 0)
		{
			perror("Error writing prompt");
			exit(EXIT_FAILURE);
		}
	}
}

