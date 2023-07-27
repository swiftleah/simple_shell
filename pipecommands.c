#include "main.h"

void execute_piped_commands(char *args[MAX_LIST], int pipe_pos)
{
	int i;
	int pipefd[2];
	pid_t pid1;
	pid_t pid2;
	char *cmd1_args[MAX_LIST];
    char *cmd2_args[MAX_LIST];

    for (i = 0; i < pipe_pos; i++)
    {
        cmd1_args[i] = args[i];
    }
    cmd1_args[pipe_pos] = NULL;

    for (i = 0; args[pipe_pos + i + 1] != NULL; i++)
    {
        cmd2_args[i] = args[pipe_pos + i + 1];
    }
    cmd2_args[i] = NULL;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return;
    }

    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork");
        return;
    }
    else if (pid1 == 0)
    {
        close(pipefd[0]); 

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execute_args(cmd1_args);
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 < 0)
    {
        perror("fork");
        return;
    }
    else if (pid2 == 0)
    {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        execute_args(cmd2_args);
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

