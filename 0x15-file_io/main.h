#ifndef FILE_IO_H
#define FILE_IO_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to standard output
 * @filename: the name of the file to read
 * @num_bytes: the number of bytes to read
 *
 * Return: the number of bytes read, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t num_bytes);

/**
 * create_file - creates a new file with the given content
 * @filename: the name of the file to create
 * @text_content: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content);

/**
 * append_text_to_file - appends text to an existing file
 * @filename: the name of the file to append to
 * @text_content: the content to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content);

#endif
