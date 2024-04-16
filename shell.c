#include "main.h"

/**
*main - a simple shell
*@av: argument verctor
*@ac: argument counter
*
*Return: 0 on success
*/
int main(int ac __attribute__ ((unused)), char **av __attribute__ ((unused)))
{
	char *line = NULL, **command, exiting[] = "exit", envb[] = "env";
	size_t n = 0;
	pid_t pid;

	signal(SIGINT, handle_sigs);
	while (true)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = read_line(&n);
		if (_strncmp(line, exiting, _strlen(exiting)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (_strncmp(line, envb, _strlen(envb)) == 0)
		{
			free(line);
			line = NULL;
			n = 0;
			env_b();
			continue;
		}
		command = tokenize(line);
		if (command == NULL)
		{
			free(line);
			line = NULL;
			n = 0;
			continue;
		}
		command[0] = _which(command[0]);
		if (command[0] == NULL)
		{
			doing(line, command, av[0], &n);
			continue;
		}
		pid = fork();
		executing(line, command, &n, pid);
	}
	return (EXIT_SUCCESS);
}

/**
*freedom - frees two memory location at the same time
*@ptr1: pointer
*@ptr2: pointer
*
*/
void freedom(char *ptr1, char **ptr2)
{
	free(ptr1);
	free(ptr2);
}

/**
*freedom3 - frees three memory location at the same time
*@ptr1: pointer
*@ptr2: pointer
*@ptr3: pointer
*
*/
void freedom3(char *ptr1, char **ptr2, char *ptr3)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
	ptr3 = NULL;
}
/**
*doing - do something about it
*@line: line pointer
*@command: pointer
*@av: av pointer
*@n: pointer to n
*/
void doing(char *line, char **command, char *av, size_t *n)
{
	dprintf(STDERR_FILENO, "%s: Not found\n", av);
	free(line);
	free(command);
	*n = 0;
	line = NULL;
}

/**
*executing - works after fork
*@line: pointer
*@command: pointer
*@n: ssize_t variable
*@pid: pid
*
*/
void executing(char *line, char **command, size_t *n, pid_t pid)
{
	int status;

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(line);
			freedom(command[0], command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		freedom3(command[0], command, line);
		*n = 0;
		if (pid == -1)
			exit(EXIT_FAILURE);
	}
}
