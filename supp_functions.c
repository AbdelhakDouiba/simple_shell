#include "main.h"

/**
*_strncmp - comapare n bytes of two strings
*@a: sting
*@b: string
*@size: number of bytes
*
*Return: 0 if success, -1 on failure
*/
int _strncmp(char *a, char *b, int size)
{
	int i;

	if (a == NULL || b == NULL || size == 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (a[i] != b[i])
			return (-1);
	}
	return (0);
}

/**
*copy - copy two strings into one string
*@a: destination
*@str1: source 1
*@str2: source 2
*
*/
void copy(char *a, char *str1, char *str2)
{
	int i = 0, j = 0;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	while (str1[i] != '\0')
	{
		a[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		a[i] = str2[j];
		i++;
		j++;
	}
	a[i] = '\0';
}

/**
*simplecopy - copy a sring
*@a: destination
*@str1: source
*
*/
void simplecopy(char *a, char *str1)
{
	int i = 0;

	if (str1 == NULL)
		str1 = "";
	while (str1[i] != '\0')
	{
		a[i] = str1[i];
		i++;
	}
	a[i] = '\0';
}
