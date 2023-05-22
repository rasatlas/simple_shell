#include "simpleShell.h"

/**
 * _help - print help
 * @args: argument
 * Return: 1 if it runs
 */

int _help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < num_builtins(); i++)
	{
		printf(" -> %s\n", builtin_func_list[i]);
	}
	printf("Use the man command for information ono other programs. \n\n");
	return (-1);
}
