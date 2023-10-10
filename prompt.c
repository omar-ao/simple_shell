#include "main.h"
/**
 * prompt - prints the prompt
 *
 */
void prompt(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &n, stdin);
		if (nread == -1)
			break;
		write(STDOUT_FILENO, line, nread);
	}
	free(line);
}
