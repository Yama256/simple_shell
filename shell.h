#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list.
 * @num: the number field.
 * @str: a string.
 * @next: points to the next node.
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct.
 * @arg: a string generated from getline containing arguements.
 * @argv:an array of strings generated from arg.
 * @path: a string path for the current command.
 * @argc: the argument count.
 * @line_count: the error count.
 * @err_num: the error code for exit()s.
 * @linecount_flag: if on count this line of input.
 * @fname: the program filename.
 * @env: linked list local copy of environ.
 * @environ: custom modified copy of environ from LL env.
 * @history: the history node.
 * @alias: the alias node.
 * @env_changed: on if environ was changed.
 * @status: the return status of the last exec'd command.
 * @cmd_buf: address of pointer to cmd_buf, on if chaining.
 * @cmd_buf_type: CMD_type ||, &&, ;.
 * @readfd: the fd from which to read line input.
 * @histcount: the history line number count.
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function.
 * @type: the builtin command flag.
 * @func: the function.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_1string.c */
int _strlen(char *s);
int _strcmp(char *x, char *y);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

/* toem_2string.c */
char *starts_with(const char *haystack, const char *needle);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strcpy(char *dest, char *src, int n);

/* toem_memory_function.c */
char *_memset(char *f, char b, unsigned int n);
void ffree(char **ll);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int bfree(void **ptr);

	/* toem_memory_errors0.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_memory_realloc.c */
char *_memset(char *f, char a, unsigned int x);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* toem_memory_ memory.c */
int bfree(void **ptr)

#endif
