#ifndef MAIN_H
#define MAIN_H

#include "utils.h"
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define DELIMS " \t\n"

extern char **environ;

void prompt(void);
void readline(void);
char **tokenize(char *);
void handle(char **);
int is_valid(char *);
void execute(char **);
char *_getenv(char *);
char *get_path(char **);

void tests(char *);

#endif
