#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* LIBRARIES */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* MACROS */
#define TOKEN_DELIMITER " \t\r\n\a\""
extern char **environ;

/* PROTOTYPES */

void interactive(void);
void noninteractive(void);
char *_getline(void);
char **tokenizer(char *line);
int execute_args(char **args);
char *_getstream(void);
int new_path(char **args);
int num_builtins(void);
int _cd(char **args);
int custom_exit(char **args);
int _env(char **args);
int _help(char **args);

#endif
