#include "main.h"

/**
*handle_sigs - handle signals
*@n: integer
*/
void handle_sigs(int sin)
{
	if (sin == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
