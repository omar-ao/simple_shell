#include "main.h"

/**
 * handle_list - This handles sequences such as and, or and list
 *
 * @tokens: Pointer to tokens
 * Return: 0 on success or non zero on failure
 */
int handle_list(char **tokens)
{
	char **tmp = tokens;
	char **next, *op;
	int st = 0, list, and, or;
	int i = 0;

	while (*tmp)
	{
		list = _strcmp(*tmp, ";") == 0;
		and = _strcmp(*tmp, "&&") == 0;
		or = _strcmp(*tmp, "||") == 0;

		if (list || and || or)
		{
			op = *tmp;
			next = tmp + 1;
			tokens[i] = NULL;

			st = execute(tokens);
			tokens = next;

			if ((_strcmp(op, "&&") == 0) && st != 0)
				break;
			else if ((_strcmp(op, "||") == 0) && st == 0)
				break;
		}
		tmp++;
		i++;
	}
	return (st);
}

/**
 * list_found - Searches if there is list in the input command
 *
 * @tokens: Pointer to pointer to string
 * Return: 1 if found, or 0 if not found
 */
int list_found(char **tokens)
{
	int i = 0, list, and, or;

	while (tokens[i])
	{
		list = _strcmp(tokens[i], ";") == 0;
		and = _strcmp(tokens[i], "&&") == 0;
		or = _strcmp(tokens[i], "||") == 0;

		if (list || and || or)
			return (1);
		i++;
	}
	return (0);
}
