#include "main.h"

/**
 * execute - Executes the input command
 *
 * @args: Pointer to command line arguments
 * Return: 0 on success
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}
