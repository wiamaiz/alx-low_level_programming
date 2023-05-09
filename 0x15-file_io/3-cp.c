#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define EXIT_USAGE_ERROR 97
#define EXIT_READ_ERROR 98
#define EXIT_WRITE_ERROR 99
#define EXIT_CLOSE_ERROR 100

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
        dprintf(STDERR_FILENO, "%s: Exiting with status %d\n", message, exit_code);
    else
        dprintf(STDERR_FILENO, "%s: %s: Exiting with status %d\n", message, filename, exit_code);

    exit(exit_code);
}

/**
 * copy_file - Copies the content of one file to another
 *
 * @file_from: The name of the file to copy from
 * @file_to: The name of the file to copy to
 *
 *

