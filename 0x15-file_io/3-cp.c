#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints an error message to stderr.
 *
 * @msg: The error message to print.
 */
void print_error(char *msg)
{
	dprintf(2, "Error: %s\n", msg);
}

/**
 * copy_file - Copies the content of one file to another.
 *
 * @src: The source file descriptor.
 * @dest: The destination file descriptor.
 */
void copy_file(int src, int dest)
{
	char buffer[BUFFER_SIZE];
	ssize_t n_read, n_written;

	while ((n_read = read(src, buffer, sizeof(buffer))) > 0)
	{
		n_written = write(dest, buffer, n_read);
		if (n_written != n_read || n_written < 0)
		{
			print_error("Can't write to file");
			exit(99);
		}
	}

	if (n_read < 0)
	{
		print_error("Can't read from file");
		exit(98);
	}
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		print_error("Can't read from source file");
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_to < 0)
	{
		print_error("Can't write to destination file");
		exit(99);
	}

	copy_file(fd_from, fd_to);

	if (close(fd_from) < 0 || close(fd_to) < 0)
	{
		print_error("Can't close files");
		exit(100);
	}

	return (0);
}
