#include "simpleShell.h"

/**
 * _getstream - a function that reads a line.
 * Return: char pointer that points to the read line.
 */

char *_getstream(void)
{
	int bufferSize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufferSize);
	int ch;

	if (line == NULL)
	{
		fprintf(stderr, "Memory allocation error in _getstream.");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ch = getchar();
		if (ch == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (ch == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = ch;
		}
		i++;
		if (i >= bufferSize)
		{
			bufferSize += bufferSize;
			line = realloc(line, bufferSize);
			if (line == NULL)
			{
				fprintf(stderr, "Memory reallocation error in _getstream.");
				exit(EXIT_FAILURE);
			}
		}
	}
}
