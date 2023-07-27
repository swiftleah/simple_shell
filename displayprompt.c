#include "main.h"
/**
 * displayprompt - displays '$' prompt for user input
 * @show_prompt: int flag for prompt to be shown
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

