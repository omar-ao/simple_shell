#ifndef SHELL_H
#define SHELL_H

/**
 * struct fixed - Struct fixed_in
 *
 * @fixed: The fixed function name
 * @f: The function associated
 */
typedef struct fixed
{
	char *fixed;
	int (*f)(char **tokens);
} fixed_t;

int func_exit(char **tokens);
int func_env(char **tokens);
int manip_env(char **tokens);
int func_cd(char **tokens);
int func_alias(char **tokens);
int (*get_func(char *cmd))(char **tokens);

#endif
