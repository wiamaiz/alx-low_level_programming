#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		perror("Error");
		free(buffer);
		exit(98);
	}
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		perror("Error");
		close_file(from);
		free(buffer);
		exit(99);
	}

	do {
		r = read(from, buffer, 1024);
		if (r == -1)
		{
			perror("Error");
			close_file(from);
			close_file(to);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (w == -1)
		{
			perror("Error");
			close_file(from);
			close_file(to);
			free(buffer);
			exit(99);
		}

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
