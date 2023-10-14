#include "main.h"

/**
 * func_exit - Exits the shell
 *
 * @tokens: Pointer to tokenised input string
 * Return: Status
 */
int func_exit(char **tokens, int err_count)
{
	int exit_arg;
	char *err_msg = "Illegal number";
	if (tokens[1])
	{
		exit_arg = _atoi(tokens[1]);
		if (exit_arg == -1)
		{
			/* handle error */
			print_err(tokens[0], err_msg, err_count);
			return (1);
		}
		else
		{
			err_count++;
			exit(exit_arg);
		}
	}
	exit(0);
}

/**
 * func_env - Prints the current environment
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_env(char **tokens, int err_count)
{
	int i;

	(void) tokens;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	err_count++;
	return (0);
}

/**
 * manip_env - Manipulates the environment
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int manip_env(char **tokens, int err_count)
{
	(void) tokens;
	/* TODO */
	err_count++;
	return (0);
}

/**
 * func_cd - Changes the current working directory
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_cd(char **tokens, int err_count)
{
	(void) tokens;
	/* TODO */
	err_count++;
	return (0);
}

/**
 * func_alias - Handles the alis command
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_alias(char **tokens, int err_count)
{
	(void) tokens;
	/* TODO */
	err_count++;
	return (0);
}
