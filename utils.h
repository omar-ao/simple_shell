#ifndef STRINGS_H
#define STRINGS_H

unsigned int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int _strlen(char *s);
char *_strdup(char *str);
char *_strtok(char *s, char *);
int get_ntokens(char *s);
char *_strpbrk(char *s, char *accept);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, int len);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
void modify_env(char *, char *);
int get_env_index(char *);
int handle_list(char **);
int list_found(char **);

#endif
