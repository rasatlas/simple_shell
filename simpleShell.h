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

/*---main.c---*/
void interactive(void);
void noninteractive(void);

/*---shell_interactive---*/
char *_getline(void);
char **tokenizer(char *line);
int execute_args(char **args);

/*---shell_non_interactive---*/
char *_getstream(void);

/*---execute_args---*/
int new_path(char **args);
int num_builtins(void);

/*---builtin---*/
int _cd(char **args);
int custom_exit(char **args);
int _env(char **args);
int _help(char **args);

#endif
