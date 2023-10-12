#include "main.h"
/**
 * readline - reads line
 *
 */
void readline(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;
	char **tokens;

	while (1)
	{
		nread = getline(&line, &n, stdin);
		if (nread == -1)
			break;
		tokens = tokenize(line);
		if (*tokens == NULL)
			continue;
		handle(tokens);
	}
	free(line);
}
