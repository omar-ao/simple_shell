#include "main.h"

/**
 * get_func - Gets a pointer to the function that corresponds to command
 * given as a parameter
 *
 * @cmd: The command passed as a parameter
 *
 * Return: Function pointer
 */
int (*get_func(char *cmd))(char **tokens, int err_count)
{
	fixed_t cmds[] = {
		{"exit", func_exit},
		{"env", func_env},
		{"setenv", manip_env},
		{"unsetenv", manip_env},
		{"cd", func_cd},
		{"alias", func_alias},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 6)
	{
		if (_strcmp(cmds[i].fixed, cmd) == 0)
		{
			return (cmds[i].f);
		}
		i++;
	}
	return (cmds[6].f);
}
