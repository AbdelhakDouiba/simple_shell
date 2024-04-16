#include "main.h"

/**
*env_b - command env
*
*/
void env_b(void)
{
	char **en = environ;

	while (*en != NULL)
	{
		printf("%s\n", *en);
		en++;
	}
}
