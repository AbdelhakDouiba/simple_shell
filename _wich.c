#include "main.h"

/**
*_which - find the path for a given command
*@command: string
*
*Return: path to the command
*/
char *_which(char *command)
{
	int a, b;
	char path[] = "PATH=", *p, *ways, *file, *tmp;
	const char delim[] = ":\n";
	struct stat st;

	if ((stat(command, &st)) == 0)
		return (command);
	p = _getenv((const char *)path);
	if (p == NULL)
		return (NULL);
	ways = strtok(p, delim);
	if (ways == NULL)
	{
		free(p);
		free(command);
		return (NULL);
	}
	b = _strlen(command);
	while (ways != NULL)
	{
		a = _strlen(ways);
		file = (char *)malloc(sizeof(char) * (a + b + 2));
		if (file == NULL)
		{
			free(command);
			free(p);
			return (NULL);
		}
		copy(file, ways, "/");
		copy(file, file, command);
		if (fileexist(file, &st) != NULL)
		{
			tmp = strtok(p, delim);
			free(tmp);
			return (file);
		}
		ways = strtok(NULL, delim);
		if (ways == NULL)
		{
			free(file);
			free(p);
			return (NULL);
		}
		free(file);
	}
	free(command);
	free(p);
	return (NULL);
}

/**
*fileexist - check the existence of a file
*@file: target file
*@st: pointer to stat structure variable
*
*Return: the file name
*/
char *fileexist(char *file, struct stat *st)
{
	if ((stat(file, st)) == 0)
	{
		return (file);
	}
	return (NULL);
}

/**
*_strlen - calculate the length of a string
*@str: The targeted string
*
*Return: the length of the string
*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
*_getenv - get the value of  a certain envirnement variable
*@str: target variable
*
*Return: the value of the envirnement variable
*/
char *_getenv(const char *str)
{
	int i, len = _strlen((char *)str), len2;
	char *value, *en;

	for (i = 0; environ[i] != NULL; i++)
	{
		en = environ[i];
		if (_strncmp((char *)str, en, len) == 0)
		{
			len2 = _strlen(en);
			value = (char *)malloc(sizeof(char) * (len2 + 1));
			if (value == NULL)
				return (NULL);
			simplecopy(value, en + len + 1);
			return (value);
		}
	}
	return (NULL);
}
