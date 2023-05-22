#include "simpleShell.h"

/**
 * main - function that chechs the shell
 *
 * Return: 0
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		noninteractive();
	}
	return (0);
}
