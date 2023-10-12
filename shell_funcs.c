#include "main.h"

/**
 * func_exit - Exits the shell
 *
 * @tokens: Pointer to tokenised input string
 * Return: Status
 */
int func_exit(char **tokens)
{
	if (tokens[1])
	{
		exit(_atoi(tokens[1]));
	}
	exit(0);
}

/**
 * func_env - Prints the current environment
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_env(char **tokens)
{
	int i;

	(void) tokens;
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}

/**
 * manip_env - Manipulates the environment
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int manip_env(char **tokens)
{
	(void) tokens;
	/* TODO */
	return (0);
}

/**
 * func_cd - Changes the current working directory
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_cd(char **tokens)
{
	(void) tokens;
	/* TODO */
	return (0);
}

/**
 * func_alias - Handles the alis command
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_alias(char **tokens)
{
	(void) tokens;
	/* TODO */
	return (0);
}
