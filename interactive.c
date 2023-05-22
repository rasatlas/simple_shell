#include "simpleShell.h"

/**
 * interactive - simple shell interactive mode handler.
 * Return: void.
 */

void interactive(void)
{
	char *feed;
	char **args;
	int status = -1;

	do {
		printf("simple_shell$ ");
		feed = _getline();
		args = tokenizer(feed);
		status = execute_args(args);

		free(feed);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
