#include "main.h"

/**
*tokenize - split a string into tokens
*@line: target string
*
*Return: an array of tokens, or NULL on failure
*/
char **tokenize(char *line)
{
	int i = 0, num = 0;
	char **target, *token;
	const char delim[] = " \t\n";

	for (token = strtok(line, delim); token != NULL; token = strtok(NULL, delim))
	{
		num++;
	}
	if (num == 0)
		return (NULL);
	target = (char **)malloc(sizeof(char *) * (num + 1));
	if (target == NULL)
		return (NULL);
	for (token = strtok(line, delim); token != NULL; token = strtok(NULL, delim))
	{
		target[i] = token;
		i++;
	}
	target[i] = NULL;
	return (target);
}
