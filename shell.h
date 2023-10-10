#ifndef SHELL_H
#define SHELL_H

/**
 * struct fixed_in - Struct fixed_in
 *
 * @fixed: The fixed function name
 * @f: The function associated
 */
typedef struct fixed
{
	char *fixed;
	int (*f)(char **tokens);
} fixed_t;
