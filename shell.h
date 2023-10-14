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
	int (*f)(char **tokens, int);
} fixed_t;

int func_exit(char **tokens, int);
int func_env(char **tokens, int);
int manip_env(char **tokens, int);
int func_cd(char **tokens, int);
int func_alias(char **tokens, int);
int (*get_func(char *cmd))(char **tokens, int);

#endif
