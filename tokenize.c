#include "main.h"

/**
 * tokenize - Generates tokens from the input string
 *
 * @s: Pointer to stream of characters
 * Return: Pointer to array of tokens
 */
char **tokenize(char *s)
{
	char **tokens;
	char *token;
	int n, i = 0;

	n = get_ntokens(s);
	tokens = malloc((n + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = _strtok(s, DELIMS);
	while (token)
	{
		tokens[i++] = _strdup(token);
		token = _strtok(NULL, DELIMS);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * _strtok - Gets a token from string
 *
 * @s: Pointer to stream of characters
 * @delims: Pointer to stream of delimeters
 * Return: Token
 */
char *_strtok(char *s, char *delims)
{
	/* TODO */
	return (NULL);
}

/**
 * get_ntokens - Gets the number of tokens in string
 *
 * @s: Pointer to stream of characters
 * Return: Number of tokens
 */
int get_ntokens(char *s)
{
	int n = 0;
	char *token;

	token = _strtok(s, DELIMS);
	while (token)
	{
		n++;
		token = _strtok(NULL, DELIMS);
	}
	return (n);
}
