#include "simpleShell.h"

/**
 * custom_exit - ends process and exits simple_shell
 * @args: argument
 * Return: 0 to end the process
 */

int custom_exit(char **args)
{
	int i, n;

	if (args[1])
	{
		n = atoi(args[1]);
		if (n <= -1)
			n = 2;
		free(args);
		exit(n);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	exit(0);
}
