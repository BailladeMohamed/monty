#include "monty.h"

/**
 * of - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void of(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		eror(2, file_name);

	readf(fd);
	fclose(fd);
}

/**
 * readf - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readf(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = sep_line(buffer, line_number, format);
	}
	free(buffer);
}
