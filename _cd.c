#include "simpleShell.h"

/**
 * _cd - changes the working dir
 * @args: target directory
 * Return: 1
 */

int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error in _cd: changing dir\n");
		}
	}
	return (-1);
}
