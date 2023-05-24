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

/**
 * _strlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}
