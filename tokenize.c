#include "main.h"
#include <string.h>

/**
 * tokenize - Generates tokens from the input string
 *
 * @str: Pointer to stream of characters
 * Return: Pointer to array of tokens
 */
char **tokenize(char *str)
{
	char *s = _strdup(str);
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

	token = strtok(s, DELIMS);
	while (token)
	{
		tokens[i++] = _strdup(token);
		token = strtok(NULL, DELIMS);
	}
	tokens[i] = NULL;
	free(s);
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
	(void) s;
	(void) delims;
	/* TODO */
	return (NULL);
}

/**
 * get_ntokens - Gets the number of tokens in string
 *
 * @str: Pointer to stream of characters
 * Return: Number of tokens
 */
int get_ntokens(char *str)
{
	int n = 0;
	char *token;
	char *s = _strdup(str);

	token = strtok(s, DELIMS);
	while (token)
	{
		n++;
		token = strtok(NULL, DELIMS);
	}
	free(s);
	return (n);
}
