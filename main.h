#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>

extern char **environ;

char **tokenize(char *);
int _strlen(char *str);
int _strncmp(char *a, char *b, int size);
void copy(char *a, char *str1, char *str);
char *_getenv(const char *str);
void simplecopy(char *a, char *str);
char *_which(char *command);
void handle_sigs(int n);
void env_b(void);
char *fileexist(char *file, char *p,struct stat *st);

#endif
