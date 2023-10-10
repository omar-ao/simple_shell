#ifndef MAIN_H
#define MAIN_H

#include "strings.h"
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DELIMS " \t\n"

void prompt(void);
void readline(void);
char **tokenize(char *);

#endif
