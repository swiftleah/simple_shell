#include "main.h"

void error_exit(void)
{
	perror("Memory allocation failed");
	exit(EXIT_FAILURE);
}

