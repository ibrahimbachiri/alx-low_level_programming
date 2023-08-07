#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - Copies the content of one file to another.
 *
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 *
 * Return: On success, returns 0. Otherwise, exits with an error code.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[1024];
	int n;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_to < 0)
	{
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	while ((n = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		if (write(fd_to, buffer, n) != n)
		{
			dprintf(2, "Error: Can't write to file %s\n", argv[2]);
			exit(99);
		}
	}

	if (n < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(fd_from) < 0 || close(fd_to) < 0)
	{
		dprintf(2, "Error: Can't close files\n");
		exit(100);
	}

	return (0);
}
