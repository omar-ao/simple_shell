#include "main.h"

/**
 * _setenv - Change or addd and environment variable
 *
 * @name: Environment variable name
 * @value: Environment variable value
 *
 * Return: 0 on success or -1 on failure
 */
int _setenv(char *name, char *value)
{
	char **env = environ, **new_env, *sign, *var;
	int len = 0, i = 0;

	if (_getenv(name) != NULL)
	{
		modify_env(name, value);
		return (0);
	}

	while (*environ)
	{
		len++;
		environ++;
	}
	new_env = malloc(sizeof(char *) * (len + 2));
	if (new_env == NULL)
		return (-1);

	sign = _strcat(name, "=");
	var = _strcat(sign, value);

	for (i = 0; i < len; i++)
		new_env[i] = env[i];
	new_env[i] = _strdup(var);
	new_env[i + 1] = NULL;

	environ = new_env;

	return (0);
}

/**
 * _unsetenv - deletes variable name from the environment
 * @name: Environment variable name
 * Return: 0 on Success or -1 on Error
 */
int _unsetenv(char *name)
{
	int index = get_env_index(name);

	environ[index] = NULL;
	return (0);
}

/**
 * modify_env - edit existing variable with new value
 * @name: Environment variable name
 * @value: Environment variable value
 */
void modify_env(char *name, char *value)
{
	char *var;
	char *sign;
	int index = get_env_index(name);

	sign = _strcat(name, "=");
	var = _strcat(sign, value);

	environ[index] = _strdup(var);
}

/**
 * get_env_index - get the index of the variable in the enviroment
 * @name: Environment variable name
 * Return: index on Success
 */
int get_env_index(char *name)
{
	char **env = environ;
	int index = 0;

	while (*env)
	{
		index++;
		env++;
		if (_strncmp(name, *env, _strlen(name)) == 0)
			break;
	}
	return (index);
}
