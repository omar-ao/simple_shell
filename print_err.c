#include "main.h"

/**
 * print_err - Prints error message to the standard error
 * @cmd_name: command
 * @err_msg: error message
 * @err_count: error count
 */
void print_err(char *cmd_name, char *err_msg, int err_count)
{
	char *name = _getenv("_");
	char *msg = _strcat(name, ": ");
	int len = _strlen(msg);

	msg[len] = err_count + '0';
	msg[len + 1] = '\0';
	msg = _strcat(msg, ": ");
	msg = _strcat(msg, cmd_name);
	msg = _strcat(msg, ": ");
	msg = _strcat(msg, err_msg);

	write(2, msg, _strlen(msg));
	write(2, "\n", 1);

	free(msg);
}

/**
 * print_exiterr - Prints exit error message
 *
 * @cmd: Command name
 * @err: Error message
 * @n: Error count
 * @arg: Exit argument
 */
void print_exiterr(char *cmd, char *err, int n, char *arg)
{
	char *name = _getenv("_");
	char *msg = _strcat(name, ": ");
	int len = _strlen(msg);

	msg[len] = n + '0';
	msg[len + 1] = '\0';
	msg = _strcat(msg, ": ");
	msg = _strcat(msg, cmd);
	msg = _strcat(msg, ": ");
	msg = _strcat(msg, err);
	msg = _strcat(msg, ": ");
	msg = _strcat(msg, arg);

	write(2, msg, _strlen(msg));
	write(2, "\n", 1);

	free(msg);
}
