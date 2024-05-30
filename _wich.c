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
	char path[] = "PATH=", *p, *ways, *file;
	const char delim[] = ":\n";
	struct stat st;

	if ((stat(command, &st)) == 0 && command[0] == '/')
		return (command);
	if ((stat(command, &st)) != 0 && command[0] == '/')
		return (NULL);
	p = _getenv((const char *)path);
	if (p == NULL)
		return (NULL);
	ways = strtok(p, delim);
	if (ways == NULL)
	{
		freeptr2(p, command);
		return (NULL);
	}
	b = _strlen(command);
	while (ways != NULL)
	{
		a = _strlen(ways);
		file = (char *)malloc(sizeof(char) * (a + b + 2));
		if (file == NULL)
		{
			freeptr2(command, p);
			return (NULL);
		}
		copy(file, ways, "/");
		copy(file, file, command);
		if (exitance(file, p) == 0)
		{ free(command);
			return (file);
		}
		ways = strtok(NULL, delim);
		if (ways == NULL)
		{ free(command);
			freeptr2(file, p);
			return (NULL);
		}
		free(file);
	}
	freeptr2(command, p);
	return (NULL);
}

/**
*freeptr2- free two memory locations
*@ptr1: pointer
*@ptr2: pointer
*/
void freeptr2(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
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
