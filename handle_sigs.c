#include "main.h"

/**
*handle_sigs - handle signals
*@n: integer
*/
void handle_sigs(int n)
{
	if (n == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
