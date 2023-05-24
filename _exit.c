#include "simpleShell.h"

/**
 * custom_exit - ends process and exits simple_shell
 * @args: argument
 * Return: 0 to end the process
 */

int custom_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}

	else
	{
		return (0);
	}
}
