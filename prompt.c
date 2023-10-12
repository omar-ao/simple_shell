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
	char **tokens;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &n, stdin);
		if (nread == -1)
			break;
		tokens = tokenize(line);
		if (*tokens == NULL)
			continue;
		handle(tokens);
	}
	if (line != NULL)
		free(line);
	exit(EXIT_SUCCESS);
}

/**
 * handle - Handles tokens
 *
 * @tokens: Pointer to array of tokens
 */
void handle(char **tokens)
{
	int (*fixed)(char **);
	char *full_path;

	fixed = get_func(tokens[0]);
	if (fixed == NULL)
	{
		if (is_valid(tokens[0]))
		{
			execute(tokens);
		}
		else
		{
			/* create path */
			full_path = get_path(tokens);
			if (full_path != NULL)
			{
				tokens[0] = full_path;
				execute(tokens);
			}
		}
	}
	else
	{
		fixed(tokens);
	}
}

/**
 * is_valid - Validates the input command
 *
 * @cmd: Pointer to input command
 * Return: 1 if valid otherwise 0
 */
int is_valid(char *cmd)
{
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	return (0);
}
