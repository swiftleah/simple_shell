#include "main.h"
/**
 * process_input - processes input from user
 * @show_prompt: displays prompt using write to stdout
 * Return: nothing
 */
void process_input(int show_prompt)
{
	int exit_status = 0, c, is_terminal = isatty(fileno(stdout));
	char *line = NULL, *args[MAX_LIST], buffer[BUFFER_SIZE];
	ssize_t line_size, buffer_index = 0;
	FILE *input_stream = stdin;

	while (1)
	{
		if (show_prompt && is_terminal)
			displayprompt(show_prompt);
		while ((c = fgetc(input_stream)) != EOF && c != '\n')
		{
			buffer[buffer_index++] = c;
			if (buffer_index >= BUFFER_SIZE - 1)
				break;
		}
		buffer[buffer_index] = '\0';
		if (buffer_index == 0 && c == EOF)
			break;
		line_size = buffer_index;
		buffer_index = 0;
		line = (char *)malloc((line_size + 1) * sizeof(char));
		if (line == NULL)
			error_exit();
		strncpy(line, buffer, line_size + 1);
		parseinput(line, args);
		if (args[0] == NULL)
		{
			free(line);
			continue;
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			shell_exit(args, exit_status);
		}
		else
			execute_args(args);
		free(line);
		if (!show_prompt && !is_terminal && c == EOF)
			break;
	}
}

/**
 * execute_args - executes builtin or command
 * @args: arguments
 * Return: nothing
 */
void execute_args(char *args[MAX_LIST])
{
	int i;
	int exit_status = 0;
	int user_exit_code;

	(void)exit_status;

	if (strcmp(args[0], "cd") == 0)
		change_dir(args);
	else if (strcmp(args[0], "exit") == 0)
	{
		user_exit_code = atoi(args[1]);
		shell_exit(args, user_exit_code);
	}
	else if (strcmp(args[0], "setenv") == 0)
		set_env(args);
	else if (strcmp(args[0], "unsetenv") == 0)
		unset_env(args);
	else
	{
		for (i = 0; i < num_builtins(); i++)
		{
			if (strcmp(args[0], builtin_str[i]) == 0)
			{
				(*builtin_func[i])(args);
				break;
			}
		}
		if (i == num_builtins())
			exit_status = execute_command(args);
	}
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: exit
 */
int main(int argc, char *argv[])
{
	int exit_status = 0;
	int show_prompt;

	signal(SIGINT, handle_sigint);
	show_prompt = 1;

	if (argc > 1)
	{
		if (strcmp(argv[1], "-n") == 0)
			show_prompt = 0;
	}

	if (isatty(fileno(stdin)))
	{
		process_input(show_prompt);
	}
	else
	{
		process_input(0);
	}
	return (exit_status);
}
/**
 * handle_sigint - signal handler for Ctrl-C
 * @sig: int for signal
 * Return: nothing
 */
void handle_sigint(int sig)
{
	char newline = '\n';

	if (sig == SIGINT)
	{
		write(1, &newline, 1);
		exit(0);
	}
}
/**
 * process_args - processes command-line arguments into buffer
 * @argc: argument count
 * @argv: argument vector
 * Return: nothing
 */
void process_args(int argc, char *argv[])
{
	int i;
	int offset = 0;
	size_t arg_len;
	size_t copy_len;
	char buffer[MAX_BUFFER_LENGTH];
	size_t max_buffer_length = MAX_ARG_LENGTH;

	(void)argc;

	for (i = 1; i <= MAX_ARGS; i++)
	{
		if (i > 1)
			buffer[offset++] = ' ';

		arg_len = strlen(argv[i]);

		copy_len = arg_len < max_buffer_length - offset ? arg_len : max_buffer_length
			- offset - 1;
		strncpy(buffer + offset, argv[i], copy_len);
		offset += copy_len;
	}
	buffer[offset] = '\0';
}

