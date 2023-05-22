#include "simpleShell.h"

/**
 * new_path - create a new path
 * @args: array of string which contane the command and it's flag
 * Return: 1 if it runs, otherwise 0
 */

int new_path(char **args)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in simple_shell");
		}
		exit(EXIT_FAILURE);

	}
	else if (pid < 0)
	{
		perror("error in new_path: forking");
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (-1);
}
