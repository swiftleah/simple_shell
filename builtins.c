#include "shell.h"
int num_builtins(void);

char *builtin_str[] = {
	"cd",
	"exit"
};

int (*builtin_func[]) () = {
	&change_dir,
	&shell_exit
};

/**
 * num_builtins - returns number of elements
 * Return: int
 */
int num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(builtin_str[0]));
}

