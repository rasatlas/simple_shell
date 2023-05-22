#include "simpleShell.h"

/**
 * _env - function that prints enviroment var
 * @args: The argument
 * Return: 1 if it runs
 */

int _env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
