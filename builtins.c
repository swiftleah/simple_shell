#include "shell.h"
int num_builtins(void);

char *builtin_str[] = {
	"cd",
	"exit",
	"env"
};

int (*builtin_func[]) () = {
	&change_dir,
	&shell_exit,
	&print_env
};

/**
 * num_builtins - returns number of elements
 * Return: int
 */
int num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(builtin_str[0]));
}

