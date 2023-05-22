#include "simpleShell.h"

/**
 * _getline - a function that reads a line from stdin.
 * Return: char pointer to the read string.
 */

char *_getline(void)
{
	char *line = NULL;
	size_t bufferSize = 0;

	if (getline(&line, &bufferSize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error in _readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
