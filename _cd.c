#include "simpleShell.h"

/**
 * _cd - changes the working dir
 * @args: target directory
 * Return: 1
 */

int _cd(char **args)
{
	char *new_dir;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = args[1];
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return (0);
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);

	return (1);
}
