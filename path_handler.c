#include "main.h"
#include <string.h> /* TODO: remove */
/**
 * _getenv - Gets the value of the environment value
 *
 * @name: Environmnet variable name
 * Return: Return value or NULL if not found
 */
char *_getenv(char *name)
{
	char **env = environ;
	char *sign;
	size_t len;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		sign = _strchr(env[i], '=');
		if (sign != NULL)
		{
			len = sign - env[i];
			if (_strncmp(env[i], name, len) == 0)
			{
				return (sign + 1);
			}
		}
	}
	return (NULL);
}

/**
 * get_path - Gets the full absolute path of the command
 *
 * @tokens: Pointer to array of tokens
 * Return: Absolute path
 */
char *get_path(char **tokens)
{
	struct stat st;
	char *path, *token, *cmd, *full_path, *path_dup, *token_dup;
	int len;

	cmd = *tokens;
	path = _getenv("PATH");
	path_dup = _strdup(path);
	if (path_dup == NULL)
		return (NULL);
	token = strtok(path_dup, ":");
	while (token)
	{
		len = _strlen(token) + _strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
			return (NULL);
		token_dup = _strdup(token);
		if (token_dup == NULL)
			return (NULL);
		full_path = _strcat(token_dup, "/");
		full_path = _strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
