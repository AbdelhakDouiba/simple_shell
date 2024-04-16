#include "main.h"

/**
*read_line - read command line
*@n: integer pointer
*
*Return: the line;
*/
char *read_line(size_t *n)
{
	char *line;

	if (getline(&line, n, stdin) == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	return (line);
}
