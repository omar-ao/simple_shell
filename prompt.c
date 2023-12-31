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
		write(STDOUT_FILENO, "$ ", 2);
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
	_free(tokens);
	exit(EXIT_SUCCESS);
}

/**
 * handle - Handles tokens
 *
 * @tokens: Pointer to array of tokens
 */
void handle(char **tokens)
{
	int (*fixed)(char **, int);
	char *full_path;
	char *err_msg;
	static int err_count = 1;

	fixed = get_func(tokens[0]);
	if (fixed == NULL)
	{
		if (is_valid(tokens[0]))
		{
			execute(tokens);
			err_count++;
		}
		else
		{
			/* create path */
			full_path = get_path(tokens);
			if (full_path != NULL)
			{
				tokens[0] = full_path;

				execute(tokens);
				err_count++;
			}
			else
			{
				err_msg = "not found";
				print_err(tokens[0], err_msg, err_count++);
			}
		}
	}
	else
	{
		fixed(tokens, err_count++);
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

/**
 * _free - Frees tokens
 *
 * @tokens: Pointer to pointer to string
 */
void _free(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
