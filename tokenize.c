#include "main.h"

/**
*tokenize - split a string into tokens
*@line: target string
*
*Return: an array of tokens, or NULL on failure
*/
char **tokenize(char *line)
{
	int i = 0;
	char **target;
	const char delim[] = " \t\n";

	target = (char **)malloc(sizeof(char *));
	if (target == NULL)
		return (NULL);
	target[0] = strtok(line, delim);
	if (target[0] == NULL)
		return (NULL);
	while (target[i])
	{
		target[i + 1] = strtok(NULL, delim);
		if (target[i + 1] == NULL)
			break;
		i++;
		target = (char **)realloc(target, sizeof(char *) * (i + 1));
		if (target == NULL)
		{
			free(target);
			return (NULL);
		}
	}
	return (target);
}
