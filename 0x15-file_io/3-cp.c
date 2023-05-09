#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PERMISSIONS 0664

/**
 * print_error - Prints an error message to standard error and exits the program
 *
 * @message: The error message to print
 * @filename: The name of the file to use in the error message, or NULL
 * @exit_code: The exit code to use when exiting the program
 *
 * Description: This function prints the given error message to standard error,
 * optionally including the given filename in the message. It then exits the
 * program with the given exit code.
 */
void print_error(char *message, char *filename, int exit_code)
{
    if (filename == NULL)
        dprintf(STDERR_FILENO, "%s\n", message);
    else
        dprintf(STDERR_FILENO, "%s %s\n", message, filename);

    exit(exit_code);
}

/**
 * main - Copies the content of one file to another
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 *
 * Description: This program copies the content of one file to another.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_count, write_count;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        print_error("Usage: cp file_from file_to", NULL, 97);

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        print_error("Error: Can't read from file", argv[1], 98);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
    if (fd_to == -1)
        print_error("Error: Can't write to", argv[2], 99);

    while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(fd_to, buffer, read_count);
        if (write_count == -1)
            print_error("Error: Can't write to", argv[2], 99);
        if (write_count != read_count)
            print_error("Error: Short write to", argv[2], 99);
    }

    if (read_count == -1)
        print_error("Error: Can't read from file", argv[1], 98);

    if (close(fd_from) == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);

    if (close(fd_to) == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);

    return 0;
}

