#include "simpleShell.h"

/**
 * tokenizer - tokkenizes a string based on the specified delimiter values.
 * @line: string to be tokkenized.
 * Return: pointer that points to the tokkenized string new array.
 */

char **tokenizer(char *line)
{
	int bufferSize = 1024;
	int i = 0;
	char **tokens = malloc(bufferSize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Memory allocation error in tokenizer: tokens");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITER);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;

		if (i >= bufferSize)
		{
			bufferSize += bufferSize;
			tokens = realloc(tokens, bufferSize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Memory reallocation error in tokenizer: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIMITER);
	}
	tokens[i] = NULL;
	return (tokens);
}
