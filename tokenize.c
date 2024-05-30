#include "main.h"

/**
*tokenize - split a string into tokens
*@line: target string
*
*Return: an array of tokens, or NULL on failure
*/
char **tokenize(char *line)
{
	int i = 0, num = 0, j = 0;
	char **target, *token, *lpy;
	const char delim[] = " \t\n";

	if (line == NULL)
		return (NULL);
	lpy = (char *)malloc(sizeof(char) * (_strlen(line) + 1));
	if (lpy == NULL)
		return (NULL);
	simplecopy(lpy, line);
	for (token = strtok(lpy, delim); token != NULL; token = strtok(NULL, delim))
	{
		num++;
	}
	free(lpy);
	if (num == 0)
		return (NULL);
	target = (char **)malloc(sizeof(char *) * (num + 2));
	if (target == NULL)
		return (NULL);
	for (token = strtok(line, delim); token != NULL; token = strtok(NULL, delim))
	{
		target[i] = (char *)malloc(sizeof(char) * (_strlen(token) + 1));
		if (target[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(target[j]);
			free(target);
			exit(EXIT_FAILURE);
		}
		simplecopy(target[i], token);
		i++;
	}
	target[i] = NULL;
	return (target);
}
