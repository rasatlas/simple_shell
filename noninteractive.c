#include "simpleShell.h"

/**
 * noninteractive - simple shell noninteractive mode handler.
 * Return: void.
 */

void noninteractive(void)
{
	char *feed;
	char **args;
	int status = -1;

	do {
		feed = _getstream();
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
