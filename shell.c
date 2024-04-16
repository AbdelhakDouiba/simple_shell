#include "main.h"

/**
*main - a simple shell
*@av: argument verctor
*@ac: argument counter
*
*Return: 0 on success
*/
int main(int ac __attribute__ ((unused)), char **av)
{
	char *line = NULL, **command, exiting[] = "exit", envb[] = "env";
	int get, execc, status;
	size_t n = 0;
	pid_t pid;

	signal(SIGINT, handle_sigs);
	while (true)
	{
		write(STDOUT_FILENO, "$ ", 2);
		get = getline(&line, &n, stdin);
		if (get == -1)
		{
			free(line);
			n = 0;
			continue;
		}
		if (_strncmp(line, exiting, _strlen(exiting)) == 0)
		{
			free(line);
			break;
		}
		if (_strncmp(line, envb, _strlen(envb)) == 0)
		{
			free(line);
			n = 0;
			env_b();
			continue;
		}
		command = tokenize(line);
		if (command == NULL)
		{
			free(line);
			n = 0;
			continue;
		}
		command[0] = _which(command[0]);
		if (command[0] == NULL)
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", av[0]);
			free(line);
			n = 0;
			free(command);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execc = execve(command[0], command, environ);
			if (execc == -1)
			{
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", command[0]);
				free(command);
				exit(-1);
			}
		}
		else
		{
			wait(&status);
			free(line);
			n = 0;
			free(command);
		}
	}
	return (0);
}
