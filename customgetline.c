#include "shell.h"

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t total_bytes_read;
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	static ssize_t bytes_in_buffer = 0;
	int found_newline = 0;
	char c;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Malloc Error");
			return (-1);
		}
	}
	total_bytes_read = 0;
	while (!found_newline)
	{
		if (buffer_index >= (size_t)bytes_in_buffer)
		{
			bytes_in_buffer = read(fileno(stream), buffer, BUFFER_SIZE);
			if (bytes_in_buffer <= 0)
			{
				if (total_bytes_read == 0)
					return (-1);
				else
					break;
			}
			buffer_index = 0;
		}
		c = buffer[buffer_index++];
		(*lineptr)[total_bytes_read++] = c;

		if (c == '\n')
			found_newline = 1;

		if (total_bytes_read >= (ssize_t)(*n))
		{
			*n += BUFFER_SIZE;
			*lineptr = (char *)realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				perror("realloc error");
				return (-1);
			}
		}
	}
	(*lineptr)[total_bytes_read] = '\0';
	return (total_bytes_read);
}
