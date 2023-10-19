#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 on Success
 */
int main(void)
{
	if (!isatty(STDIN_FILENO))
	{
		readline();
	}
	else
	{
		prompt();
	}
	return (0);
}
