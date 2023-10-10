#include "main.h"
#include "shell.h"

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
		exit(atoi(tokens[1]));
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
	// TODO
}

/**
 * manip_env - Manipulates the environment
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int manip_env(char **tokens)
{
	// TODO
}

/**
 * func_cd - Changes the current working directory
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_cd(char **tokens)
{
	// TODO
}

/**
 * func_alias - Handles the alis command
 *
 * @tokens: Pointer to tokenised input string
 * Return: 0
 */
int func_alias(char **tokens)
{
	// TODO
}
