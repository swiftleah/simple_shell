#include "main.h"
/**
 * custom_getline - getline function
 * @lineptr: double pointer
 * @n: arg
 * @stream: stdout
 * Return: total bytes read
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t total_bytes_read;
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static ssize_t bytes_in_buffer;
	int found_newline = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);
	initialize_lineptr(lineptr, n);

	total_bytes_read = 0;
	bytes_in_buffer = 0;
	while (!found_newline)
	{
		total_bytes_read = read_buffer(lineptr, buffer, &buffer_index,
				&bytes_in_buffer, &found_newline, stream);
		if (total_bytes_read < 0)
		{
			free(*lineptr);
			return (-1);
		}
		if (total_bytes_read >= (ssize_t)(*n))
		{
			if (expand_lineptr(lineptr, n) == -1)
			{
				free(*lineptr);
				return (-1);
			}
		}
	}
	(*lineptr)[total_bytes_read] = '\0';
	return (total_bytes_read);
}
/**
 * initialize_lineptr - initializes lineptr
 * @lineptr: double pointer
 * @n: arg
 * Return: nothing
 */
void initialize_lineptr(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Malloc Failure");
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * read_buffer - reads input in buffer
 * @lineptr: double pointer
 * @buffer: buffer
 * @buffer_index: index of buffer from start
 * @bytes_in_buffer: number of bytes in buffer
 * @found_newline: int that specifies if newline has been reached
 * @stream: output stream
 * Return: buffer index
 */
ssize_t read_buffer(char **lineptr, char buffer[], size_t *buffer_index,
		ssize_t *bytes_in_buffer, int *found_newline, FILE *stream)
{
	char c;

	if (*buffer_index >= (size_t)(*bytes_in_buffer))
	{
		*bytes_in_buffer = read(fileno(stream), buffer, BUFFER_SIZE);
		if (*bytes_in_buffer <= 0)
		{
			if (*buffer_index == 0)
				return (-1);
			else
				return (*buffer_index);
		}
		*buffer_index = 0;
	}
	c = buffer[(*buffer_index)++];
	(*lineptr)[*buffer_index - 1] = c;

	if (c == '\n')
		*found_newline = 1;
	return (*buffer_index);
}
/**
 * expand_lineptr - expands lineptr
 * @lineptr: double pointer
 * @n: arg
 * Return: int
 */
int expand_lineptr(char **lineptr, size_t *n)
{
	*n += BUFFER_SIZE;
	*lineptr = (char *)realloc(*lineptr, *n);
	if (*lineptr == NULL)
	{
		perror("Realloc Error");
		return (-1);
	}
	return (0);
}

