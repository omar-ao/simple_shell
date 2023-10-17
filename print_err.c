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

	dprintf(STDERR_FILENO, "%s: %d: %s: %s\n",
			name, err_count, cmd_name, err_msg);
}
